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

ll x, y, xx, yy;

int main (){
	ll s[2];
	scanf("%lld%lld%lld%lld", &x, &y, &xx, &yy);
	s[0] = (x - xx)*(x - xx) + (y - yy)*(y - yy);
	scanf("%lld%lld%lld%lld", &x, &y, &xx, &yy);
	s[1] = (x - xx)*(x - xx) + (y - yy)*(y - yy);
	for(ll i = 1;i*i <= min(s[0], s[1]);i++){
		ll k = i*i;
		if(s[0]%k != 0)
			continue;
		ll div = s[0]/k;
		if(s[1]%div == 0 && ((ll)sqrt(s[1]/div))*((ll)sqrt(s[1]/div)) == s[1]/div){
			puts("YES");
			printf("%.6f\n", sqrt(s[0]/k));
			return 0;
		}
	}
	puts("NO");
}
