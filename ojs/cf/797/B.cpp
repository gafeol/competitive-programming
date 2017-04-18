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
ll s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
	}
	ll sum = 0, mnp = LLONG_MAX, mxn = LLONG_MIN;
	for(int a=0;a<n;a++){
		if(s[a] > 0){
			sum += s[a];
			if(s[a]&1)
				mnp = min(mnp, s[a]);
		}
		else{
			if(s[a]&1)
				mxn = max(mxn, s[a]);
		}
	}
	if(sum&1)
		printf("%lld\n", sum);
	else{
		if(mnp != LLONG_MAX && mxn != LLONG_MIN){
			printf("%lld\n", max(sum-mnp, sum+mxn));
		}
		else if(mnp != LLONG_MAX)
			printf("%lld\n", sum-mnp);
		else
			printf("%lld\n", sum+mxn);
	}
}
