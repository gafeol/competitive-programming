#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

vector<pair<int, ll>> adj[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);

    set<ll> val;
    val.insert(0ll);
	for(int a=0;a<m;a++){
        int i, j;
        ll c;
        scanf("%d%d%lld", &i, &j, &c);
        i--;j--;
        adj[i].eb(j, c);
        adj[j].eb(i, c);
        val.insert(c);
	}

    ll res = LLONG_MAX;
    while(!val.empty()){
        ll x = *val.begin(); 
        val.erase(val.begin());

        vector<ll> dis(n, LLONG_MAX);
        set<pair<ll, int>> q;
        dis[0] = 0;
        q.insert({dis[0], 0});
        while(!q.empty()){
            auto [d, u] = *q.begin();
            q.erase(q.begin());
            for(auto [nxt,cus]: adj[u]){
                cus = max(0ll, cus - x);
                if(dis[nxt] > dis[u] + cus){
                    if(dis[nxt] != LLONG_MAX)
                        q.erase({dis[nxt], nxt});
                    dis[nxt] = dis[u] + cus;
                    q.insert({dis[nxt], nxt});
                }
            }
        }
        res = min(res, dis[n-1] + k*x);
    }
    printf("%lld\n", res);
    return 0;
}

