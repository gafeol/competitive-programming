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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

ll expo(ll b, ll e){
	if(e == 0)
		return 1;
	
	ll ans = expo(b, e/2);
	ans = mod(ans*ans);

	if(e&1)
		ans = mod(ans*b);

	return ans;
}

int main (){
	scanf("%d", &n);
	modn = n;
	if(n == 1){
		puts("YES\n1");
		return 0;
	}
	if(n == 4){
		puts("YES\n1\n3\n2\n4");
		return 0;
	}
	for(int a=2;a<=sqrt(n);a++){
		if(n%a == 0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	puts("1");
	for(int a=2;a<n;a++){
		printf("%lld\n", mod(a*expo(a-1, n-2)));
	}
	printf("%d\n", n);
}
