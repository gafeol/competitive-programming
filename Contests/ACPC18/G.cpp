#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 112345;
const int LOGN = 21;

int n, m, k;
int s[MAXN];

ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int gcdt[MAXN][LOGN];

unordered_map<int, vector<tuple<int, int, int, int>>> tuples;

inline void get_tuples(){
    for(int a=n-1;a>=0;a--){
        gcdt[a][0] = s[a];
        for(int i=1;i<=LOGN;i++){
            int nxt = a + (1<<(i-1));
            if(nxt < n)
                gcdt[a][i] = gcd(gcdt[a][i-1], gcdt[nxt][i-1]);
            else
                gcdt[a][i] = gcdt[a][i-1];
        }
    }

    for(int i=0;i<n;i++){
        int j1 = i;
        int gc = 0;
        while(j1 < n){
            gc = gcd(gc, s[j1]);
            int j2 = j1;
            for(int st=LOGN-1;st>0;st--){
                if(gcd(gc, gcdt[j2][st]) == gc){
                    j2 = min(n-1, j2 + (1<<(st-1)));
                }
            }
            if(tuples.find(gc) != tuples.end()) 
                tuples[gc].pb({i, 1, j1, j2});
            //printf("tuples %d pb %d %d %d\n", gc, i, j1, j2);
            j1 = j2+1;
        }
    }
}

struct arv{
    ll s, lz;
    bool z;
} tree[4*MAXN];

inline void unlaze(int idx, int i, int j){
    if(tree[idx].z){
        tree[idx].z = 0;
        if(i != j){
            tree[idx*2].s = tree[idx*2].lz = 0; 
            tree[idx*2].z = 1;
            tree[1+idx*2].s = tree[1+idx*2].lz = 0; 
            tree[1+idx*2].z = 1;
        }
    }
    if(tree[idx].lz != 0){
        ll aux = tree[idx].lz; 
        tree[idx].lz = 0;

        if(i != j){
            int m = (i+j)/2;
            tree[idx*2].lz += aux;
            tree[idx*2+1].lz += aux;
            tree[idx*2].s += (m - i + 1)*aux;
            tree[idx*2+1].s += (j-m)*aux;
        }
    }
}

void upd(int idx, int i, int j, int l, int r, ll x){
    if(i > r || j < l) return ;
    unlaze(idx, i, j);
    if(i >= l && j <= r){
        tree[idx].lz += x;
        tree[idx].s += (j - i + 1)*x;
        return ;
    }
    int m = (i + j)/2;
    upd(idx*2, i, m, l, r, x);
    upd(idx*2+1, m+1, j, l, r, x);
    tree[idx].s = tree[idx*2].s + tree[idx*2+1].s;
}

ll qry(int idx, int i, int j, int l, int r){
    if(i > r || j < l) return 0; 
    unlaze(idx, i, j);
    if(i >= l && j <= r)
        return tree[idx].s;
    int m = (i + j)/2;
    return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

int main (){
    freopen("gcdrng.in", "r", stdin);
    for_tests(t, tt){
        tuples.clear();
        scanf("%d%d", &n, &m);
        vector<ll> ans(m);
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
        }
        for(int a=0;a<m;a++){
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            l--;
            r--;
            tuples[d].pb({l, 0, r, a});
        }
        get_tuples();
        for(auto it: tuples){
            tree[1].z = 1;
            tree[1].s = tree[1].lz = 0;
            int gc = it.fst;
            //printf("gc  %d\n", gc);
            vector<tuple<int, int, int, int>> v = it.snd;
            sort(v.begin(), v.end(), greater<tuple<int, int, int, int>>());
            for(tuple<int, int, int, int> tp: v){
                int i, t, j1, j2;
                tie(i, t, j1, j2) = tp;
                debug("i %d ", i);
                if(t == 1){
                    debug("upd %d - %d com 1\n", j1, j2);
                    upd(1, 0, n-1, j1, j2, 1);       
                }
                else{
                    ans[j2] = qry(1, 0, n-1, i, j1);
                    debug("qry %d - %d ans[%d] %d\n", i, j1, j2, ans[j2]);
                }
            }
        }
        for(int a=0;a<m;a++){
            printf("%lld\n", ans[a]);
        }
    }
}

