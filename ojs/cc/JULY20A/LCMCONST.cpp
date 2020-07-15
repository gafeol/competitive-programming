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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 40;

int n, m, k;

int s[MAXN];
vector<pii> adj[MAXN];
vector<int> mx;

ll go(int u=1){
    if(u == n+1)
        return 1;

    //printf("go %d\n", u);
    ll ans0 = 0, ans1 = 0;
    s[u] = 1;
    for(pii p: adj[u]){
        int prv = p.fst;
        int val = p.snd;
        if(mx[u] < val && (s[prv] == 0 || mx[prv] < val))
            return 0;
    }
    ans1 = go(u+1);
    //printf("colocando s[%d] = %d tenho %lld\n", u, mx[u], ans1);
    if(mx[u] > 0){
        s[u] = 0;
        bool ok = true;
        for(pii p: adj[u]){
            int prv = p.fst;
            int val = p.snd;
            if(s[prv] == 0 || mx[prv] < val){
                ok = false;
                break;
            }
        }
        if(ok){
            ans0 = mod(mx[u]*go(u+1));
            //printf("colocando s[%d] < %d tenho %lld\n", u, mx[u], ans0);
        }
    }

    return mod(ans0 + ans1);
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        vector<map<int, int>> v(m);
        vector<int> l(m), r(m);
        set<int> pri;
        for(int a=0;a<m;a++){
            scanf("%d%d%d", &l[a], &r[a], &k);
            if(l[a] > r[a]) swap(l[a], r[a]);
            map<int, int> cnt;
            while(k--){
                int p, e;
                scanf("%d%d", &p, &e);
                pri.insert(p);
                cnt[p] += e;
            }
            v[a] = cnt;
        }
        bool inf = false;
        if(m == 0)
            inf = true;

        assert(pri.size() <= 5);
        if(pri.empty())
            pri.insert(1);
        ll ans = 1;
        for(int p: pri){
            unordered_map<int, unordered_map<int, int>> ex;
            mx.resize(n+1);
            for(int a=0;a<=n;a++){
                adj[a].clear();
                mx[a] = INT_MAX;
            }

            for(int a=0;a<m;a++){
                int val = v[a][p];
                if(mx[l[a]] < val && mx[r[a]] < val)
                    goto imp;
                if(ex[l[a]].find(r[a]) != ex[l[a]].end()){
                    if(ex[l[a]][r[a]] == val)
                        continue;
                    else
                        goto imp;
                }
                mx[l[a]] = min(mx[l[a]], val); 
                mx[r[a]] = min(mx[r[a]], val); 
                ex[l[a]][r[a]] = val;
                adj[r[a]].pb({l[a], val});
            }


            //check
            for(int a=0;a<m;a++){
                int val = v[a][p];
                if(val != mx[l[a]] && val != mx[r[a]])
                    goto imp;
                if(max(mx[l[a]], mx[r[a]]) > val)
                    goto imp;
            }

            if(inf || *max_element(mx.begin()+1, mx.end()) == INT_MAX) {
                inf = true;
                continue;
            }

            ans = mod(ans*go());


        }

        if(inf)
            puts("-1");
        else
            printf("%lld\n", ans);

        continue;
imp:    puts("0");
    }
}

