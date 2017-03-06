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
int s[MAXN], mrk[MAXN], deg[MAXN];
vector<int> adj[MAXN], res;

void go(int u){
	res.pb(u);
	mrk[u] = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);
		res.pb(u);
	}
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	int tam = (int)ceil((2.*n)/k);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	go(1);
	debug("tam %d\n", tam);
	int cnt = 0;
	for(int a=0;a<res.size();a++){
		if(a%tam == 0){
			printf("\n%d ", min(tam, (int)res.size() - a));
			cnt++;
		}
		printf("%d ", res[a]);
	}
	printf("\n");
	while(cnt < k){
		puts("1 1");
		cnt++;
	}
}
