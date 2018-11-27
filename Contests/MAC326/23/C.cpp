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

int n, m;
ll k;
ll d[MAXN];

vector<tuple<int, ll, ll> > adj[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d%lld", &n, &m, &k);
		for(int a=1;a<=n;a++){
			d[a] = LLONG_MAX;
			adj[a].clear();
		}
		for(int a=0;a<m;a++){
			int i, j;
			ll c, w;
			scanf("%d%d%lld%lld", &i, &j, &c, &w);
			adj[i].pb({j, c, w});
			adj[j].pb({i, c, w});
		}

		ll i = 0, j = 1e9 + 3;
		while(i < j){
			ll m = ((i + j)>>1);
			set<tuple<ll, int>> q;
			for(int a=1;a<=n;a++)
				d[a] = LLONG_MAX;
			d[1] = 0;
			q.insert({0, 1});
			while(!q.empty()){
				ll dis; int u;
				tie(dis, u) = *q.begin();
				q.erase(q.begin());
				for(auto ares: adj[u]){
					int v;
					ll c, w;
					tie(v, c, w) = ares;
					if(w > m) continue;
					if(d[v] > dis + c){
						if(d[v] != LLONG_MAX)
							q.erase({d[v], v});
						d[v] = dis + c;	
						q.insert({d[v], v});
					}
				}
			}
			
			if(d[n] < k)
				j = m;
			else
				i = m+1;
		}
		if(i > (int)1e9)
			puts("-1");
		else
			printf("%lld\n", i);
	}
}

