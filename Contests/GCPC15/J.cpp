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

const int MAXN = 101, MAXC = 20, MAXP = 500;
const int INF = 0x3f3f3f3f;

int n, m, k, g;
char s[MAXN][20];

char t[MAXN][MAXC];

int p[MAXN], pc[MAXN];

int dp[MAXN][MAXN][MAXP];

int ch(int i){
	int tro = k - p[i];
	if(s[i][1] == 'e')
		return pc[i]*(tro/pc[i] + (tro%pc[i] != 0));
	else if(s[i][1] == 'o'){
		int sob = tro%pc[i];
		int mais = 0;
		if(sob+sob >= pc[i])
			mais = 1;
		return pc[i]*(tro/pc[i] + mais); 
	}
	else
		return pc[i]*(tro/pc[i]);
}

int go(int i, int ng, int np){
	if(ng < 0)
		return -INF;
	if(np >= MAXP)
		return -INF;
	if(dp[i][ng][np] != -1)
		return dp[i][ng][np];
	int &r = dp[i][ng][np];

	if(i == n) return r = 0;
	r = max(r, go(i+1, ng, np));
	if(np >= p[i])
		r = max(r, go(i+1, ng, np - p[i]) + 1);
	if(s[i][1] != 'e' || np < p[i])
		r = max(r, go(i+1, ng-1, np + ch(i)) + 1);

	return r;
}

int main (){
	scanf("%d %d %d", &k, &g, &n);
	for(int a=0;a<n;a++){
		scanf(" %s %d %d", s[a], &pc[a], &p[a]); 
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, g, 0));
}
