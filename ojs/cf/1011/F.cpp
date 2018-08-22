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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN][10];
int L[MAXN], R[MAXN];
int in[MAXN];
int p[MAXN];
int val[MAXN];

int go(int u){
	if(s[u][0] == 'A')
		val[u] = (go(L[u])&go(R[u]));
	else if(s[u][0] == 'O')
		val[u] = (go(L[u])|go(R[u]));
	else if(s[u][0] == 'N')
		val[u] = !go(L[u]);
	else if(s[u][0] == 'X')
		val[u] = (go(L[u])^go(R[u]));
	else
		val[u] = in[u];
	return val[u];
}

int dp[MAXN][2];

int solve(int u, int f, int lstval){
	int aft;
	int l = (L[u] == f ? lstval : val[L[u]]);
	int r = (R[u] == f ? lstval : val[R[u]]);

	if(s[u][0] == 'A')
		aft = (l&r);
	else if(s[u][0] == 'O')
		aft = (l|r);
	else if(s[u][0] == 'N')
		aft = !l;
	else if(s[u][0] == 'X')
		aft = (l^r);
	else
		aft = lstval;
	if(u == 1){
		return dp[u][aft] = aft;
	}
	if(dp[u][aft] == -1) dp[u][aft] = solve(p[u], u, aft);
	return dp[u][aft];
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int a=1;a<=n;a++){
		scanf(" %s", s[a]);	
		if(s[a][0] == 'A' || s[a][0] == 'O' || s[a][0] == 'X'){
			scanf("%d %d", L+a, R+a);
			p[L[a]] = a;
			p[R[a]] = a;
		}
		if(s[a][0] == 'I')
			scanf("%d", in+a);
		if(s[a][0] == 'N'){
			scanf("%d", L+a);
			p[L[a]] = a;
		}
	}
	go(1);
	for(int a=1;a<=n;a++)
		dp[a][val[a]] = val[1];
	for(int a=1;a<=n;a++){
		if(s[a][0] == 'I'){
			printf("%d", solve(a, a, 1-val[a]));		
		}
	}
}
