
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
ll res;

inline ll pa(ll rz, ll no){
	return ((rz + no*rz)*no)/2ll;
}

int main (){
	scanf("%lld%lld", &n, &k);
	if(k == 1){
		printf("%lld", n);
	}
	res = -1;
	ll sum = 0;
	for(ll r=1;r<=sqrt(n) + 1;r++){
		sum = pa(r, k-1);	
		if(sum >= n)
			break;
		if(n-sum > r*(k-1) && (n - sum)%r == 0){
			res = r;
		}
	}
	if(res == -1){
		puts("-1");
		return 0;
	}
	sum = 0;
	for(ll a=1;a<=k-1;a++){
		sum += res*a;
		printf("%lld ", res*a);
	}
	printf("%lld\n", n-sum);
}
