
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000000;

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

int test(ll e, int inv){
	if(expo(a, e) == mod(c)){
		if(!inv)
			printf("%lld\n", e);
		else
			printf("%lld\n", p-e-1);
		return 1;
	}
	return 0;
}

ll ans;

void dif(ll A, ll B){
	printf("A %lld B %lld\n", A, B);
	assert(A == B);
}

void fail(){
	dif(ans, INT_MAX);
	puts("NIE");
}

int mrk[MAXN];

vector<ll> pri;

int main(){
	for(ll j=2;j<MAXN;j++){
		if(mrk[j]) continue;
		pri.push_back(j);
		for(ll i=j;i*j<MAXN;i++){
			mrk[i*j] = 1;
		}
	}
	srand(time(NULL));
	int cnt = 0;
	while(1){
		p = pri[rand()%((int)pri.size()-1)];
		a = rand()%min(10000ll, p);
		b = rand()%min(10000ll, p);
		x = rand()%min(10000ll, p);
		x0 = rand()%min(10000ll, p);
		printf("case #%d p %lld a %lld b %lld x %lld x0 %lld\n",++cnt,  p, a, b, x, x0);
		modn = p;

		ll i = 0;
		ll f = x0;
		int ok = 0;
		clock_t clk = clock();
		while((clock() - clk)/CLOCKS_PER_SEC < 0.3){
			if(f == x){
				ok = 1;
				break;
			}
			f = mod(a*f + b);
			i++;
		}
		ans = i;
		if(!ok) ans = INT_MAX;
		printf("ANS = %lld f %lld\n", i, f);


		if(x0 == x){
			dif(ans, 0);
			puts("0");
			continue;
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
			continue;
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
			continue;
		}
		ll sup = mod(x*(a-1)+b);
		ll bai = mod(x0*(a-1)+b);
		if(bai == 0 || sup == 0){
			fail();
			continue;
		}
		c = mod(sup*expo(bai, modn-2));
		ll lg = (long double)log(c)/((long double)log(a));
		int ook = 0;
		for(int i=0;i<=min(lg, 100000ll);i++){
			ook = test(lg-i, 0);
			if(ook) break;
		}
		if(ook) continue;
		for(int i=0;i<=100000;i++){
			ook = test(lg+i, 0);
			if(ook) break;
		}
		if(ook) continue;
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
}
