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

const int MAXN = 4123456;

int n, m, k;
ll s[MAXN];
ll val[MAXN];

ll sq(ll x){
	return x*x;
}

ll nxtsq(ll x){
	ll raiz = (ll)sqrt(x);
	return sq(raiz+1);
}

bool issq(ll x){
	ll raiz = (ll)sqrt(x);
	return (sq(raiz) == x || sq(raiz-1) == x || sq(raiz+1) == x);
}

int main (){
	scanf("%d", &n); 
	for(int a=2;a<=n;a+=2){
		scanf("%lld", s+a);
	}
	ll sum = 0;
	for(int a=1;a<=n;a+=2){
		int st = 1000;
		bool ok = false;
		ll test = nxtsq(sum + s[a+1]);
		while(st--){
			if(issq(test-s[a+1])){
				ok = true;
				s[a] = test-s[a+1]-sum;
				break;
			}
			test = nxtsq(test);
		}
		if(!ok){
			puts("No");
			return 0;
		}
		sum += s[a] + s[a+1];
	}
	puts("Yes");
	for(int a=1;a<=n;a++){
		printf("%lld ", s[a]);
	}
	puts("");
}

