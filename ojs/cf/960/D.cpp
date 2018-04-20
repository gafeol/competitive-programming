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
const ll modn =1000000007;
inline ll ind(ll x, ll m) { return ((((x-m)%m) + m)%m) + m; }

const int MAXN = 212345;

int n, m, k;

ll sh[MAXN], f[MAXN];

inline ll lv(ll x){
	ll cnt = 0;
	while(x > 1ll){
		x /= 2ll;
		cnt++;
	}
	return cnt;
}



void print(ll h, ll x){
	int ini = 1;
	while(h > 0){
		if(!ini)
			printf("%lld ", ind(x+sh[h], (1LL<<h))); 
		else{
			printf("%lld ", x);
			x = ind(x-sh[h], (1LL<<h));
		}
		ini = 0;
		if(f[h])
			x = ind(x + f[h], (1LL<<h));
		ll p = x/2ll;
		h--;
		x = p;
	}
	puts("1");
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		ll x, k;
		if(t == 1){
			scanf("%lld %lld", &x, &k);
			ll h = lv(x);
			ll qt = (1LL<<h);
			sh[h] = (qt + ((sh[h] - k)%qt))%qt;
		}
		else if(t == 2){
			scanf("%lld %lld", &x, &k);
			ll h = lv(x);
			ll qt = (1LL<<h);
			f[h] = (qt + ((f[h] + k)%qt))%qt;
		}
		else{
			scanf("%lld", &x);
			print(lv(x), x);
		}
	}
}

