#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plp;
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

int n, pai[MAXN], sz[MAXN];
ll m, k;

struct pti{
	ll x, y;
} s[MAXN];

set<plp> q;

ll d(int a, int b){
	return (s[a].x - s[b].x)*(s[a].x - s[b].x) + (s[a].y - s[b].y)*(s[a].y - s[b].y);
}

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	if(sz[u] < sz[v])
		swap(u, v);
	pai[v] = u;
	sz[u] += sz[v];
}

double rail, road;

int main (){
	for_tests(t, tt){
		rail = road = 0;
		scanf("%d%lld", &n, &m);
		m *= m;
		k = 1;
		for(int a=0;a<n;a++){
			scanf("%lld %lld", &s[a].x, &s[a].y);
			pai[a] = a;
			sz[a] = 1;
		}
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				q.insert(plp(d(a, b), pll(a, b)));
			}
		}
		while(!q.empty()){
			plp t = *q.begin();
			q.erase(t);
			int u = t.snd.fst;
			int v = t.snd.snd;
			if(raiz(u) == raiz(v))
				continue;
			join(u, v);
			if(t.fst > m){
				rail += sqrt(t.fst);
				k++;
			}
			else
				road += sqrt(t.fst);
		}
		printf("Case #%d: %lld %lld %lld\n", tt, k, (ll)(road + 0.5), (ll)(rail + 0.5));
	}
}
