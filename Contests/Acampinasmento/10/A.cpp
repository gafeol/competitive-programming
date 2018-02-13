
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modn;

inline ll mod(ll x) { return x%modn; }

int n;

ll p, x0, x, a, b;

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if((e&1))
		ans = mod(ans*base);
	return ans;
}

ll c;

void test(ll e, int inv){
	if(expo(a, e) == mod(c)){
		if(!inv)
			printf("%lld\n", e);
		else
			printf("%lld\n", p-e-1);
		exit(0);
	}
}

ll ans;

void dif(ll A, ll B){
	//printf("%lld %lld\n", A, B);
	//assert(A == B);
}

void fail(){
	dif(ans, INT_MAX);
	puts("NIE");
	exit(0);
}

int main(){
	scanf("%lld%lld%lld%lld%lld", &p, &x0, &a, &b, &x);
	modn = p;

	ll i = 0;
	ll f = x0;
	/*
	int ok = 0;
	clock_t clk = clock();
	while((clock() - clk)/CLOCKS_PER_SEC < 3){
		if(f == x){
			ok = 1;
			break;
		}
		f = mod(a*f + b);
		i++;
	}
	ans = i;
	if(!ok) ans = INT_MAX;
	*/


	if(x0 == x){
		dif(ans, 0);
		puts("0");
		return 0;
	}
	if(a == 0){
		if(b == x){
			dif(ans, 1);
			puts("1");
		}
		else{
			dif(ans, INT_MAX);
			puts("NIE");
		}
		return 0;
	}
	if(a == 1){
		if(b == 0){
			dif(ans, INT_MAX);
			printf("NIE\n");
		}
		else{
			ll co = mod(mod(mod(x - x0)+modn)*expo(b,modn-2));
			dif(ans, co);
			printf("%lld\n", co);
		}
		return 0;
	}
	ll sup = mod(x*(a-1)+b);
	ll bai = mod(x0*(a-1)+b);
	if(bai == 0 || sup == 0)
		fail();
	c = mod(sup*expo(bai, modn-2));
	ll lg = (long double)log(c)/((long double)log(a));
	for(int i=0;i<=min(lg, 1000000ll);i++)
		test(lg-i, 0);
	for(int i=0;i<=1000000;i++)
		test(lg+i, 0);
	/*
	swap(sup, bai);
	c = mod(sup*expo(bai, modn-2));
	lg = (long double)log(c)/((long double)log(a));
	printf("lg %lld\n", lg);
	for(int i=0;i<=min(lg, 100000ll);i++)
		test(lg-i, 1);
	for(int i=0;i<=100000;i++)
		test(lg+i, 1);
		*/
	dif(ans, INT_MAX);
	puts("NIE");
}
