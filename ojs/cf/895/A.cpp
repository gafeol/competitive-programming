
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

int dp[MAXN];

int main (){
	dp[0] = 1;
	scanf("%d", &n);
	int tot = 360;
	for(int a=0;a<n;a++)
		scanf("%d", s+a);
	int sum = 0;
	int res = 360;
	for(int a=0;a<n;a++){
		sum = 0;
		for(int b=a;b<n;b++){
			sum += s[b];
			res = min(res, abs(tot - 2*sum));
		}
	}
	printf("%d\n", res);
}
		
