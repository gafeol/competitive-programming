#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
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
int s[MAXN], l[MAXN], r[MAXN], sum[MAXN], pai[MAXN], mrk[MAXN], sz[MAXN];

int res[MAXN], d[MAXN];

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	if(u == v) return;
	if(sz[u] < sz[v])
		swap(u, v);
	sz[u] += sz[v];
	sum[u] += sum[v];
	pai[v] = u;
}

main (){
	scanf("%lld", &n);
	pai[0] = 0;
	pai[n+1] = n+1;
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
		pai[a] = a;
		sum[a] = s[a];
	}
	for(int a=1;a<=n;a++){
		scanf("%lld", &d[a]);
	}
	res[n+1]= 0;
	for(int a=n;a>0;a--){
		res[a] = res[a+1];
		int pl = raiz(d[a]-1);
		int pr = raiz(d[a]+1);
		mrk[d[a]] = 1;
		if(mrk[pl]){
			join(pl, d[a]);
		}
		if(mrk[pr])
			join(pr, d[a]);
		res[a] = max(res[a], sum[raiz(d[a])]);
	}
	for(int a=2;a<=n+1;a++){
		printf("%lld\n", res[a]); 
	}
}
