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

const int MAXN = 112345;
const ll INF = LLONG_MAX - 10000000000;

int n, m, es[MAXN], k;
ll d[MAXN];

vector <pii> adj[MAXN];

set <pii> s;

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<=n;a++){
		d[a] = INF;
	}
	for(int a=0;a<m;a++){
		int j, i, k;
		scanf("%d%d%d", &i, &j, &k);
		adj[i].pb(pii(j, k));
		adj[j].pb(pii(i, k));
	}
	for(int a=0;a<k;a++){
		int i;
		scanf("%d", &i);
		d[i] = 0;
		es[i] = 1;
		s.insert(pii(d[i], i));
	}
	while(!s.empty()){
		pii t = *s.begin();
		s.erase(t);
		int u = t.snd;
		for(pii nxt:adj[u]){
			if(d[nxt.fst] > d[u] + nxt.snd){
				if(d[nxt.fst] != INF)
					s.erase(pii(d[nxt.fst], nxt.fst));
				d[nxt.fst] = d[u] + nxt.snd;
				s.insert(pii(d[nxt.fst], nxt.fst));
			}
		}
	}
	ll mn = INF;
	for(int a=1;a<=n;a++){
		if(!es[a])
			mn = min(mn, d[a]);
	}
	if(mn == INF)
		puts("-1");
	else{
		printf("%lld\n", mn);
	}
}


