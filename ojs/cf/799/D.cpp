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

const int MAXN = 112345;

int n, m, k;
ll s[MAXN];
int dp[MAXN];

bool cmp(int a, int b){
	return a>b;
}

int x, y, X, Y;

bool valid(ll a, ll b){
	return ((a*x >= X && b*y >= Y) || (a*y >= Y && b*x >= X) || (a*x >= Y && b*y >= X) || (b*x >= Y && a*y >= X));

}

int main (){
	scanf("%d %d %d %d %d", &X, &Y, &x, &y, &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);		
	}
	sort(s, s+n, cmp);
	if(valid(1, 1)){
		puts("0");
		return 0;
	}
	dp[1] = 1;
	ll mul = 1;
	for(int a=0;a<n;a++){
		mul *= s[a];
		for(ll i = MAXN-1;i > 0;i--){
			if(dp[i] != 0){
				if(valid(mul/(i*s[a]), i*s[a])){
					printf("%d\n", a+1);
					return 0;
				}
				if(i*s[a] < MAXN)
					dp[i*s[a]] = 1;
			}
		}
	}
	puts("-1");
	return 0;
}
