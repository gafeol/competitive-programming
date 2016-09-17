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

int n, m, s, t, prv[MAXN];
ll L, d[MAXN], dist[MAXN][MAXN];

vector <pair<pii, ll> > ar;
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
	for(int a=0;a<m;a++){
		ll u, v;
		ll k;
		scanf("%lld %lld %lld", &u, &v, &k);
		dist[u][v] = k;
		dist[v][u] = k;
		if(k != 0ll){
			adj[u].pb(pii(v, k));
			adj[v].pb(pii(u, k));
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
////			printf("2 TURA ESSA PORREAA\n");
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
			ll u = t;
			int foi = 0;
			while(prv[u] != -1){
 				if(dist[prv[u]][u] == 0){
					if(foi == 0){
						foi = 1;
						dist[prv[u]][u] = L - d[t] + 1;
						dist[u][prv[u]] = L - d[t] + 1;
					}
					else{
						dist[prv[u]][u] = 1;
						dist[u][prv[u]] = 1;
					}
				}
				u = prv[u];
			}
			puts("YES");
			for(pair<pii, ll> a: ar){
				printf("%lld %lld ", a.fst.fst, a.fst.snd);
				if(dist[a.fst.fst][a.fst.snd] == 0)
					printf("%lld\n", L+1);
				else
					printf("%lld\n", dist[a.fst.fst][a.fst.snd]);
			}
		}
	}
}
