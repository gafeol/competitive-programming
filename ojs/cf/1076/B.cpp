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
ll res = 0;


int main (){
	scanf("%lld", &n);
	if(n%2 == 0){
		printf("%lld\n", n/2ll);
		return 0;
	}
	else{
		for(ll a=3;a<= sqrt(n);a++){
			if(n%a == 0){
				printf("%lld\n", 1 + (n-a)/2);
				return 0;
			}
		}
	}
	puts("1");
}

