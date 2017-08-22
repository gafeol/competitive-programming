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

const int N = 1e3 + 42;
const int V = (N<<1) + 42;
const int E = V*V;

int n, r, l;
int x[N], y[N];

int ad[V], seen[V], st[V], C[V], S[V], cmp, pre, ss;
int to[E], nx[E], es=1;

int dfs(int i){
	seen[i] = ++pre;
	S[i] = seen[i];
	st[ss++] = i;
	for(int e=ad[i];e;e=nx[e])
		if(!seen[to[e]])
			S[i] = min(S[i], dfs(to[e]));
		else if(!C[to[e]])
			S[i] = min(S[i], seen[to[e]]);
	if(S[i] == seen[i]){
		C[i] = ++cmp;
		while(st[ss-1] != i)
			C[st[--ss]] = C[i];
		ss--;
	}
	return S[i];
}

inline int v(int i, int b){ return (i<<1)|(b&1); }
inline int add(int i, int j){ to[es] = j; nx[es] = ad[i]; ad[i] = es++; }

int main (){
	scanf(" %d%d%d", &n, &r, &l);
	for(int i=0;i<l;i++) scanf(" %d%d", x+i, y+i);

	for(int i=0;i<l;i++)
		for(int j=i+1;j<l;j++){
			if(x[i] == x[j] && abs(y[i] - y[j]) < 2*r + 1){
				add(v(i, 0), v(j, 1));
				add(v(j, 0), v(i, 1));
			}
			if(y[i] == y[j] && abs(x[i] - x[j]) < 2*r + 1){
				add(v(i, 1), v(j, 0));
				add(v(j, 1), v(i, 0));
			}
		}
	for(int i=0;i<l;i++)
		for(int b=0;b<2;b++)
			if(!seen[v(i,b)]) dfs(v(i,b));
	int ok = 1;
	for(int i=0;i<l;i++)
		ok &= (C[v(i,0)] != C[v(i,1)]);

	if(ok) puts("YES");
	else   puts("NO");
}

