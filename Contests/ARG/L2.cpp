
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
int v[MAXN], w[MAXN];
int dp[1001][1001];

int solve(int nx, int ny) {
	if (nx == n-1 && ny == m-1) return 0;
	if (dp[nx][ny] != -1) return dp[nx][ny];
	if (nx > n-1 || ny > m-1) {
		return modn;
	}
	return dp[nx][ny] = min(solve(nx+1, ny)-(ny+1)*v[nx], solve(nx, ny+1)-(nx+1)*w[ny]);
}

int main (){
	int t;
	scanf("%d", &t);
	for (;t--;) {
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &m);
		for(int a=0;a<n-1;a++){
			scanf("%d", &v[a]);
			v[a] *= -1;
		}
		for(int a=0;a<m-1;a++){
			scanf("%d", &w[a]);
			w[a] *= -1;
		}
		sort(v, v+n-1);
		sort(w, w+m-1);
		printf("%d\n", solve(0, 0));
	}
}

