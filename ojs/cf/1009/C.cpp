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
int s[MAXN];

ll pa(ll qtd, ll d){
	return d*(qtd*(qtd-1))/2ll;
}


ll opt(ll d){
	if(d >= 0){
		return pa(n, d);
	}
	else{
		ll mid = (n+1)/2ll;
		return pa(mid, d) + pa(n+1 - mid, d);
	}
}

int main (){
	ll res = 0;
	scanf("%lld%lld", &n, &m);
	for(int a=0;a<m;a++){
		ll x, d;
		scanf("%lld %lld", &x, &d);
		res += x*n;
		res += opt(d);
	}
	double ans = res;
	printf("%.10f\n", res/((double)n));
}

