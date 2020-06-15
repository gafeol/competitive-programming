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

const int MAXN = 212345;
const int MAXV = 1123456;

int n, m, k;
vector<pii> edges[MAXV];
int p[MAXN], sz[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

bool join(int u, int v){
    u = raiz(u); v = raiz(v);
    if(u == v) return false;
    if(sz[u] < sz[v])
        swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=1;a<=n;a++){
        p[a] = a;
        sz[a] = 1;
    }
	for(int a=0;a<m;a++){
        int i, j, v;
        scanf("%d%d%d", &i, &j, &v);
        edges[v].pb({i, j});
	}
    ll res = 1, cus = 0;
    for(int val=1;val<MAXV;val++){
        int wouldJoin = 0;
        vector<pii> liga;
        for(int i=0;i<edges[val].size();i++){
            pii e = edges[val][i];
            int ra = raiz(e.fst), rb = raiz(e.snd);
            if(ra != rb){
                wouldJoin++;
                liga.pb({min(ra, rb), max(ra, rb)});
            }
        }
        sort(liga.begin(), liga.end());
        liga.erase(unique(liga.begin(), liga.end()), liga.end());
        map<int, int> cnt;
        int maxi = 0;
        for(pii p: liga){
            cnt[p.fst]++;
            cnt[p.snd]++;
            maxi = max(maxi, max(cnt[p.fst], cnt[p.snd]));
        }
        int joined = 0;
        for(int i=0;i<edges[val].size();i++){
            pii e = edges[val][i];
            joined += (int)join(e.fst, e.snd);
        }
        cus = mod(cus + val*joined);
        if(joined == 2 && liga.size() == 3 && maxi == 2)
            res = mod(res*3);
        else
            res = mod(res * (wouldJoin-joined + 1));
    }
    printf("%lld %lld\n", cus, res);
}

