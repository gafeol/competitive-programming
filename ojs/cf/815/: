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
int op;

ll fat[MAXN];

ll expo(ll e, ll base){
	if(e == 0)
		return 1;

	ll ans = expo(e/2, base);
	ans = mod(ans*ans);

	if(e&1)
		ans = mod(ans*base);
	
	return ans;
}

ll inv(ll x){
	return expo(modn-2, x);
}

void step(){
	for(int a=0;a<n-1;a++){
		s[a] =  s[a] + op*s[a+1];
		op *= -1;
	}
	n--;
}

void solve(){
	while(n > 1){
		step();
	}
	printf("%d\n", s[0]);
	exit(0);
}

ll bin(ll i, ll j){
	return mod(mod(fat[i]*inv(fat[i-j]))*inv(fat[j]));
}

int main (){
	fat[0] = 1;
	for(ll a=1;a<MAXN;a++){
		fat[a] = mod(fat[a-1]*a);
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	int op = 1;
	if(n < 4)
		solve();
	if(n&1) step();	
	int nos = n/2 - 1;
	ll A, B;
	A = B = 0;
	for(int a=0;a<n;a+=2){
		A = mod(A + bin(n/2 - 1, a/2)*s[a]);
	}
	for(int a=1;a<n;a+=2){
		B = mod(B + bin(n/2 - 1, a/2)*s[a]);
	}
	ll res = mod(A + op*B);
	printf("%lld\n", mod(res + modn));
}
