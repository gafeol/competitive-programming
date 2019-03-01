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

const double EPS = 1e-6;
ll k;

bool test(double a){
	double b = k - a;
	if(abs((a + b) - a*b) <= EPS && abs(a+b - k) <= EPS){
		printf("Y %.10f %.10f\n", a, b);
		return true;
	}
	return false;
}

int main (){
	for_tests(t, tt){
		scanf("%lld", &k);
		if(k*k-4*k >= 0 && test((k + sqrt(k*k - 4*k))/2.)) continue;
		if(k*k-4*k >= 0 && test((k - sqrt(k*k - 4*k))/2.)) continue;
		puts("N");
	}
}

