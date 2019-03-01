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

int n, m, k;
int s[MAXN];
int sz[MAXN], p[MAXN];

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);

	if(i == j) return ;

	if(sz[i] < sz[j])
		swap(i,j);
	p[j] = i;
	sz[i] += sz[j];
}

vector<int> sp;
vector<tuple<int, int, ll> > ar;

void clear(){
	for(int a=0;a<=n;a++){
		p[a] = a;
		sz[a] = 1;
	}
}

bool go(int x){
	clear();

	for(auto tp: ar){
		int u, v;
		ll cus;
		tie(u, v, cus) = tp;
		if(cus <= x){
			join(u, v);
		}
	}
	for(int u: sp){
		if(raiz(u) != raiz(sp[0]))
			return false;
	}
	return true;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);

	for(int a=0;a<k;a++){
		int x;
		scanf("%d", &x);
		sp.pb(x);
	}

	for(int a=0;a<m;a++){
		int u, v;
		ll x;
		scanf("%d%d%lld", &u, &v, &x);
		ar.pb({u, v, x});
	}

	ll i = 0, j = 1000000000;

	while(i < j){
		ll mid = (i + j)/2;

		if(go(mid))
			j = mid;
		else
			i = mid+1;
	}
	for(int x: sp){
		printf("%lld ", i);
	}
	puts("");
}

