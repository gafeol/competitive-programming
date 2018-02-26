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

const int MAXN = 5003;

int n, m, k;
char s[MAXN];

int dp[MAXN][MAXN];

int deg;
int adj[MAXN*MAXN][2];

int cnt[MAXN*MAXN];
int acu[MAXN*MAXN];

int add(int u, int d){
	if(adj[u][d] == -1)
		adj[u][d] = ++deg;
	return adj[u][d];
}

int dfs(int u){
	if(u == -1) return 0;	
	acu[u] = cnt[u] + dfs(adj[u][0]) + dfs(adj[u][1]);
	return acu[u];
}

int f(int u){
	if(u == -1) return 0;
	return acu[u];
}

void go(int u, int k){
	k -= cnt[u];
	if(k < 1) return ;
	if(f(adj[u][0]) < k){
		printf("b");
		go(adj[u][1], k-f(adj[u][0]));
		return ;
	}
	printf("a");
	go(adj[u][0], k);
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int t=0;t<n;t++){
		for(int i=0;i+t<n;i++){
			if(s[i] == s[i+t]){
				dp[i][t] = 1;
				if(t >= 4)
					dp[i][t] = dp[i+2][t-4]; 
			}
		}
	}
	memset(adj, -1, sizeof(adj));
	for(int i=0;i<n;i++){
		int u = 0;
		for(int j=i;j<n;j++){
			u = add(u, (s[j]-'a'));
			if(dp[i][j-i]){
				cnt[u]++;
			}
		}
	}
	dfs(0);
	scanf("%d", &k);
	go(0, k);
}
