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

int s[MAXN];

ll n;
char m;

ll time (ll x){
	ll ans = 0;
	ans = ((x-1)/4ll)*12ll + (!(x&1ll))*6ll;
	if((x-1)%4ll <= 1){
		ans += x-1;
	}
	else
		ans += x-3;
	return ans;
}

ll ord (char c){
	ll ans = 0;
	if(c <= 'c') ans+=3;
	if(c == 'f' || c == 'a') return ans+1;
	else if(c == 'b' || c == 'e') return ans+2;
	return ans+3;
}

int main (){
	scanf("%lld %c", &n, &m);
	ll res = 0;
	res+= time(n) + ord(m);
	//printf("time %lld ord %lld\n", time(n), ord(m));
	printf("%lld", res);
}
