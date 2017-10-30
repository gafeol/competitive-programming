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

const int MAXN = 212345, DEZ = 1e7+1;

ll t[4], c[4], sz[4];

ll res;

ll f, T;

ll ceil(ll a, ll b){
	return a/b + (a%b != 0);
}

void go(){
	for(ll cnt=0;cnt<=DEZ;cnt++){
		if(cnt*sz[1] >= f){
			if(t[1]*f <= T){
				res =  min(res, ceil(f, sz[1])*c[1]);	
			}
			return ;
		}
		if((f - sz[1]*cnt)*t[0] + sz[1]*cnt*t[1] <= T){
			res = min(res, cnt*c[1]);
		}
		if(t[2] < t[0]){
			ll qtd = min(f - cnt*sz[1], max(0ll, ceil((T - t[0]*f - cnt*sz[1]*(t[1] - t[0])), (t[2] - t[0]))));
			ll qtd0 = max(0ll, f - cnt*sz[1] - qtd);
			if(cnt*sz[1]*t[1] + qtd*t[2] + qtd0*t[0] <= T){
				res = min(res, cnt*c[1] + ceil(qtd, sz[2])*c[2]);	
			}
		}
	}
}

int main (){
	res = LLONG_MAX;
	scanf("%lld %lld %lld", &f, &T, &t[0]);
	for(int a=1;a<3;a++)
		scanf("%lld %lld %lld", &sz[a], &t[a], &c[a]);
	if(f*min({t[0], t[1], t[2]}) > T){
		puts("-1");
		return 0;
	}
	if(f*t[0] <= T){
		puts("0");
		return 0;
	}
	go();
	swap(t[1], t[2]);
	swap(c[1], c[2]);
	swap(sz[1], sz[2]);
	go();
	printf("%lld\n", res);
}

