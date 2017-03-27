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

const int MAXN = (1<<20)+10;

int n, m, k;
int s[MAXN];

ll dp[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		dp[s[a]]++;
	}
	for(int a=(1<<20)-1;a>=0;a--){
		for(int i = 0;i < 20;i++){
			if(!(a&(1<<i)))
				dp[a] = mod(dp[a] + dp[a|(1<<i)]);
		}
	}
	ll res = 0;
	for(int a=0;a<(1<<20);a++){
		if(dp[a]){
			res = mod(res + ((__builtin_popcount(a)&1) ? -1:1)*(1<<(dp[a]-1)));
			debug("a %d soma %d\n", a, ((__builtin_popcount(a)&1) ? -1:1)*(1<<(dp[a]-1)));
		}
	}
	printf("%lld\n", res);
}
