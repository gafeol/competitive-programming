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
int s[MAXN], pai[MAXN], ini[MAXN], sz[MAXN];

int raiz(int u){
	if(pai[u] == u)
		return u;
	return pai[u] = raiz(pai[u]);
}

void join(int u, int v){
	u = raiz(u);
	v = raiz(v);
	if(sz[u] < sz[v])
		swap(u, v);
	sz[u] += sz[v];
	pai[v] = u;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
		ini[a] = a+n+1;
		pai[a+n+1] = a+n+1;
		sz[a+n+1] = 1;
		ini[a+n+1] = a;
	}
	while(1){
		int t, i, j;
		scanf("%d %d %d", &t, &i, &j);
		if(t + i + j == 0) break;
		i = raiz(i);
		j = raiz(j);
		if(t == 1){
			if(i == raiz(ini[j])){
				puts("-1");
				continue;
			}
			join(i, j);
			join(ini[i], ini[j]);
		}
		else if(t == 2){
			if(i == j){
				puts("-1");
				continue;
			}
			join(i, ini[j]);
			join(ini[i], j);
		}
		else if(t == 3){
			printf("%d\n", (i == j));	
		}
		else{
			printf("%d\n", (i == raiz(ini[j]) || (raiz(ini[i]) == j)));
		}
	}
}
