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
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];
ll h[2], f[2], x[2], y[2];


void next(int i){
	h[i] = mod(h[i]*x[i] + y[i]);
}

ll mdc(ll a, ll b){
	if(a == 0) return b;
	return mdc(b%a, a);
}

ll mmc(ll a, ll b){
	return (a*b)/mdc(a, b);
}

int main (){
	scanf("%d", &m);
	modn = m;
	for(int a=0;a<2;a++){
		scanf("%lld %lld %lld %lld", &h[a], &f[a], &x[a], &y[a]);
	}
	vector<int> i, j;
	ll res = LLONG_MAX;
	for(int a=0;a<MAXN;a++){
		if(h[0] == f[0] && i.size() < 2000){
			i.pb(a);
		}
		if(h[1] == f[1] && j.size() < 2000){
			j.pb(a);
		}
		if(h[0] == f[0] && h[1] == f[1])
			res = min(res, (ll)a);
		next(0);
		next(1);
	}
	if(i.size() == 0 || j.size() == 0){
		puts("-1");
		return 0;
	}
	for(int a:i){
		for(int b:j){
			res = min(res, mmc(a, b));
		}
	}
	printf("%lld\n", res);
}
