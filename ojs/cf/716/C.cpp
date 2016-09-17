

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

ll mdc(ll a, ll b){
	if(b == 0)
		return a;
	return mdc(b, a%b);
}

ll mmc(ll a, ll b){
	return (a/mdc(a, b))*b; 
}

int main (){
	scanf("%d", &n);
	ll x = 2;
	for(ll a=1;a<=n;a++){
		ll ans = mmc(a, a+1);
		printf("%lld\n", (ans/a)*ans - (x/a));
		x = ans;
	}
}
