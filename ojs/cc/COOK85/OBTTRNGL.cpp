
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

ll n, m, k;
int s[MAXN];

int main (){
	for_tests(t, tt){
		ll A, B;
		scanf("%lld%lld%lld", &n, &A, &B);
		if(A > B) swap(A, B);
		if(180ll*n - 180ll*(B - A) == 90ll*n){
			puts("0");
		}
		else if(180ll*n - 180ll*(B-A) > 90ll*n)
			printf("%lld\n", B-A-1);
		else
			printf("%lld\n", n - (B-A+1));

	}
}

