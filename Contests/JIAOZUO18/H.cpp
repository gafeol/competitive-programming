#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;

// Suffix array Nlog2 + Kazai
inline vector<int> sa(vector<int> &s){
    int n = s.size();
    if(n == 1) // Tratar caso n = 1
        return vector<int>(1, 0);
    vector<int> r(n+1), p(n), aux(n);
    for(int a=0;a<n;a++){
        r[a] = s[a];
        p[a] = a;
    }
    r[n] = -1;

    for(int d=1;d < n;d*=2ll){
        sort(p.begin(), p.end(), [&](int a, int b){
            return make_pair(r[a], r[min(n, a+d)]) < make_pair(r[b], r[min(n, b+d)]);
                }); 
        int val = 0;
        for(int a=0;a<n;a++){
            if(a > 0)
                val += (make_pair(r[p[a]], r[min(n, p[a]+d)]) != make_pair(r[p[a-1]], r[min(n, p[a-1]+d)]));
            aux[p[a]] = val;
        }
        for(int a=0;a<n;a++)
            r[a] = aux[a];
        if(r[p[n-1]] == n-1) break;
    }

    //Kazai 
    int sz = 0;
    vector<int> lcp(n); // lcp[i] = |lcp(s[i...], s[p[r[i]+1]....])|
    for(int i=0;i<n;i++){
        if(r[i] == n-1){
            lcp[i] = sz = 0;
            continue;
        }
        int o = p[r[i]+1];
        while(i + sz < n && o + sz < n && s[i + sz] == s[o + sz])
            sz++;
        lcp[i] = sz;
        sz = max(0, sz-1);
    }
    return lcp;
}

struct arv{
    ll som, lz;
} tree[4*MAXN];

void unlaze(int idx, int i, int j){
    ll aux = tree[idx].lz;
    tree[idx].lz = 0;
    if(aux && i != j){
        int m = ((i + j)>>1);
        tree[idx*2].lz = aux;
        tree[idx*2].som = aux*(m-i+1);
        tree[idx*2+1].lz = aux;
        tree[idx*2+1].som = aux*(j-m);
    }
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].lz = x; 
        tree[idx].som = (j - i + 1)*x;
        return ;
    }

    int m = ((i + j)>>1);
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].som = tree[idx*2].som + tree[idx*2+1].som;
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return 0;
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].som;
    int m = ((i + j)>>1);
    return qry(idx*2, i, m, l, r) + 
           qry(idx*2+1, m+1, j, l, r);
}

int n, m, k;
int ind[MAXN];
set<int> q;
stack<pii> st;

int main (){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int a=0;a<4*n;a++){
            tree[a] = {0, 0};
        }
        vector<int> s(n);
        for(int a=0;a<n;a++){
            scanf("%d", &s[a]);
            ind[a] = a;
        }
        sort(ind, ind+n, [&](int a, int b) { return s[a] > s[b]; });
        ll ans = 0;
        q.insert(-1);
        q.insert(n);
        for(int aa=0;aa<n;aa++){
            int a = ind[aa];
            auto it = q.lower_bound(a);
            ll r = *it;
            ll l = *(--it);
            l++;
            r--;
            ans += ((ll)s[a])*(r-a+1ll)*(a-l+1); 
            q.insert(a);
        }
        q.clear();
        vector<int> lcp = sa(s);
        ll sum = 0;
        while(!st.empty())
            st.pop();
        st.push({INT_MAX, n});
        for(int a=n-1;a>=0;a--){
            while(st.top().fst <= s[a]){
                //printf("st top %d s[a] %d\n", st.top().fst, s[a]);
                st.pop();
            }
            //printf("upd de %d a %d com valor %d\n", a, st.top().snd-1, s[a]);
            upd(1, 0, n-1, a, st.top().snd-1, s[a]); 
            st.push({s[a], a});
            if(lcp[a] > 0){
                //printf("A %d lcp %d qry(%d - %d) %lld\n", a, lcp[a], a, a+lcp[a]-1, qry(1, 0, n-1, a, a + lcp[a]-1));
                ans -= qry(1, 0, n-1, a, a + lcp[a]-1);
            }
        }
        printf("%lld\n", ans);
    }
}
