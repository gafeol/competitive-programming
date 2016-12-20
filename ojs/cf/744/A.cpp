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

const int MAXN = 2123;

int n, m, k;
int s[MAXN], pai[MAXN];
ll sz[MAXN];
int mrk[MAXN];

vector<int> ct;

int raiz(int i){
	if(pai[i] == i)
		return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return;
	if(sz[i] < sz[j])
		swap(i, j);
	pai[j] = i;
	sz[i] += sz[j];
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<k;a++){
		int v;
		scanf("%d", &v);
		s[v] = 1;
		ct.pb(v);
	}
	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		join(i, j);
	}
	ll mx = 0, h = -1;
	for(int u: ct){
		mrk[raiz(u)] = 1;
		mx = max(mx, sz[raiz(u)]);
		if(mx == sz[raiz(u)])
			h = raiz(u);
	}
	ll cnt = 0;
	for(int u = 1;u <=n;u++){
		if(!mrk[raiz(u)]){
			mrk[raiz(u)] = 2;
			cnt+=sz[raiz(u)];
		}
	}
	ll res = -m;
	res += ((sz[h]+cnt)*(sz[h]+cnt-1))/2ll;
	mrk[raiz(h)] = 2;
	for(int a=1;a<=n;a++){
		int r = raiz(a);
		if(mrk[r] == 1){
			mrk[r] = 2;
			res += (sz[r]*(sz[r]-1))/2ll;
		}
	}
	printf("%lld\n", res);
}
