#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll modmul(ll a, ll b, ll m){
	ll ans = 0;
	for(;b;b>>=1,a = (ll(2)*a)%m)
		if(b&1)
			ans = (ans + a)%m;
	return ans;
}

ll modexp(ll a, ll e, ll m){
	ll ans = 1;
	for(;e;e>>=1,a=modmul(a,a,m))
		if(e&1)
			ans = modmul(ans, a, m);
	return ans;
}

int fermat_test(ll n){
	ll a = rand(); a <<= 31; a ^= rand();
	a = (a+n)%n;
	if(a == 0) return fermat_test(n);
	return (1 == modexp(a, n-ll(1), n));
}

int ans = 1;
ll n;

void factor(ll p){
	int cnt = 0;
	for(;n%p == 0;cnt++,n/=p);
	ans *= (++cnt);
}

int prime(ll n){
	int ok = 1;
	for(int i=0;i<500;i++)
		ok &= fermat_test(n);
	return ok;
}


int main(){
	srand(time(NULL));
	cin >> n;

	factor(2);
	factor(3);
	factor(5);
	for(ll w = 6;w*w*w <= n;w++){
		factor(++w);
		factor(w += 4);
	}

	ll rt = sqrt(n);

	if(n == 1)          ans = 1*ans;
	else if(rt*rt == n) ans = 3*ans;
	else if(prime(n))   ans = 2*ans;
	else                ans = 4*ans;

	printf("%d\n", ans);
}
