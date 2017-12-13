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

const int MAXN = 3123456;

int n, m, k;
ll s[MAXN];
ll ac[MAXN];
ll ans[MAXN];

ll f(ll x){
	ll res = 0;
	while(x != 0){
		int t = 2*((x%10)&1);
		res += (t-1)*(x%10);
		x /= 10;
	}
	return abs(res);
}

ll line(int a, int b){
	return ac[b] - ac[a-1];
}

ll check(int n){
	ll sum = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			sum += f(a+b);
		}
	}
	return sum;
}

int main (){
	for(int a=1;a<MAXN;a++){
		s[a] = f(a);
		ac[a] = ac[a-1] + s[a];
	}
	for(int a=1;a < 1000100;a++){
		ans[a] = ans[a-1] + 2*line(a+1, a+a) - s[a+a];
	}
	for_tests(t, tt){
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
}

