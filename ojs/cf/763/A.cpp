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
int res;
vector<int> adj[MAXN];

void go(int u, int pai){
	for(int nxt: adj[u]){
		if(nxt == pai) continue;
		if(s[nxt] != s[u]){
			res = 0;
			return 
		}
		go(nxt, u);
	}
}

int main (){
	scanf("%d", &n);
	res = 1;
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	int r = 1, mxd = 0;
	for(int a=1;a<=n;a++){
		int dif = 0;
		for(int nxt: adj[a]){
			dif += (s[a] != s[nxt]);
		}
		if(dif > mxd){
			r = a;
			mxd = dif;
		}
	}
	for(int nxt: adj[r]){
		go(nxt, r);
	}
	if(res)
		printf("YES\n%d\n", r);
	else
		puts("NO");
}
