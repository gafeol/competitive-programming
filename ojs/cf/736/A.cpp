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

const int MAXN = 212346;

ll n, m, k;
int s[MAXN];
ll dp[MAXN];

int main (){
	scanf("%lld", &n);
	dp[0] = 1;
	dp[1] = 2;
	int a = 2;
	for(a=2;;a++){
		dp[a] = dp[a-1] + dp[a-2];
		if(dp[a] > n){
			a--;
			break;
		}
	}
	if(n == 1) a = 0;
	if(n == 2) a = 1;
	printf("%d\n",a);
}
