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

const int MAXN = 212, MAXM = 31234;

int dp[MAXN][MAXM][3];

int s[MAXN];

int n, m, k;

int go(int i, int k, int lst){
	int &r = dp[i][k][lst];
	if(r != -1) return r;
	if(i == n) return r = 0;
	r = max(go(i+1, (lst ? m : k), lst^1), go(i+1, (k*2)/3, lst) + min(k, s[i]));
	return r;
}

int main (){
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	printf("%d\n", go(0, m, 1));
}

