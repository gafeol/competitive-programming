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
const int MAXA = 2*16*50 + 100;

int n, m, k;
int s[MAXN];
int t[MAXN], g[MAXN], r[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=1;a<n;a++)
		scanf("%d %d %d", t+a, g+a, r+a);	
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int tt=dp[i];tt <= MAXA;tt++){
			for(int j=0;<n;j++){

			}
		}
	}
}

