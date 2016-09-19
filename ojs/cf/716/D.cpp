#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123, MAXM = 11234;
const ll INF  = 1000000000000LL;

int n, m, s, t;
ll prv[MAXN];
ll L, d[MAXN], dist[MAXN][MAXN];

vector <pair<pii, ll> > ar;

stack<pii> var;
vector <pii> adj[MAXN];

set<pii> q;

pair<pii, ll> con(ll a, ll b, ll c){
	pair<pii, ll> ans;
	ans.fst.fst = a;
	ans.fst.snd = b;
	ans.snd = c;
	return ans;
}

int main (){
	scanf("%d%d%lld%d%d", &n, &m, &L, &s, &t);
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			dist[a][b] = dist[b][a] = INF;
		}
	}
	for(int a=0;a<m;a++){
		ll u, v;
		ll k;
		scanf("%lld %lld %lld", &u, &v, &k);
		dist[u][v] = INF;
		dist[v][u] = INF;
		if(k != 0ll){
			adj[u].pb(pii(v, k));
			adj[v].pb(pii(u, k));
			dist[u][v] = k;
			dist[v][u] = k;
		}
		pair<pii, ll> p = con(u, v, k);
		ar.pb(p);
	}
	for(int a=0;a<n;a++){
		d[a] = INF;
	}
	d[s] = 0ll;
	q.insert(pii(0ll, s));
	while(!q.empty()){
		ll u = q.begin()->snd;
		q.erase(q.begin());
		for(pii nxt: adj[u]){
			if(d[nxt.fst] > d[u] + nxt.snd){
				if(d[nxt.fst] != INF)
					q.erase(pii(d[nxt.fst], nxt.fst));
				d[nxt.fst] = d[u] + nxt.snd;
				q.insert(pii(d[nxt.fst], nxt.fst));
			}
		}
	}
	if(d[t] < L){
		puts("NO");
//		printf("%lld 1 TURA ESSA PORREAA\n", d[t]);
		return 0;
	}
	else if(d[t] == L){
		puts("YES");
		for(pair<pii, ll> a: ar){
			printf("%lld %lld ", a.fst.fst, a.fst.snd);
			if(a.snd == 0)
				printf("%lld\n", L+1);
			else
				printf("%lld\n", a.snd);
		}
		return 0;
	}
	else{
		for(pair<pii, ll> a: ar){
			if(a.snd == 0){
				adj[a.fst.fst].pb(pii(a.fst.snd, 1));
				adj[a.fst.snd].pb(pii(a.fst.fst, 1));
			}
		}
		for(int a=0;a<n;a++){
			d[a] = INF;
		}
		prv[s] = -1;
		d[s] = 0;
		q.insert(pii(0, s));
		while(!q.empty()){
			ll u = q.begin()->snd;
			q.erase(q.begin());
			for(pii nxt: adj[u]){
				if(d[nxt.fst] > d[u] + nxt.snd){
					if(d[nxt.fst] != INF)
						q.erase(pii(d[nxt.fst], nxt.fst));
					d[nxt.fst] = d[u] + nxt.snd;
					q.insert(pii(d[nxt.fst], nxt.fst));
					prv[nxt.fst] = u;
				}
			}
		}
		if(d[t] > L){
			puts("NO");
			return 0;
		}
		else if(d[t] == L){
			puts("YES");
			for(pair<pii, ll> a: ar){
				printf("%lld %lld ", a.fst.fst, a.fst.snd);
				if(a.snd == 0)
					printf("%lld\n", 1ll);
				else
					printf("%lld\n", a.snd);
			}
			return 0;
		}
		else{
			ll uu = t;
			while(prv[uu] != -1){
				if(dist[prv[uu]][uu] == INF){
					var.push(pii(prv[uu], uu));
					dist[prv[uu]][uu] = 1;
					dist[uu][prv[uu]] = 1;
				}
				uu = prv[uu];
			}
			puts("YES");
			while(d[t] != L){
				pii a = var.top();
				var.pop();
				printf("%lld %lld\n", a.fst, a.snd);
				dist[a.fst][a.snd] = L - d[t] + 1;
				dist[a.snd][a.fst] = L - d[t] + 1;
				d[s] = 0;
				q.insert(pii(0, s));
				while(!q.empty()){
					ll u = q.begin()->snd;
					q.erase(q.begin());
					for(pii nxt: adj[u]){
						if(dist[u][nxt.fst] != 0)
							nxt.snd = dist[u][nxt.fst];
						if(d[nxt.fst] > d[u] + nxt.snd){
							if(d[nxt.fst] != INF)
								q.erase(pii(d[nxt.fst], nxt.fst));
							d[nxt.fst] = d[u] + nxt.snd;
							q.insert(pii(d[nxt.fst], nxt.fst));
						}
					}
				}
				printf("%d %d\n", s, t);
			}
			printf("pa\n");
			for(pair<pii, ll> a: ar){
				printf("%lld %lld ", a.fst.fst, a.fst.snd);
				if(dist[a.fst.fst][a.fst.snd] == 0)
					printf("%lld\n", L+1);
				else
					printf("%lld\n", dist[a.fst.fst][a.fst.snd]);
			}
			printf("pa\n");
		}
	}
}
