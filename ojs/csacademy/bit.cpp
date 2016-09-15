#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k, pot[70], cnt[70];

ll go(ll i, ll x){
	if(i == -1) return 1;
	ll ans = 0;
	if(x&(1ll<<i)){
		if(pot[i])
			ans = go(i-1, x) + (1ll<<(cnt[i]-1));
		else
			ans = go(i-1, x);
	}
	else{
		if(pot[i])
			ans = go(i-1, x);
	}
	//printf("%lld %lld : %lld\n", i, x, ans);
	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll res =0;
		ll l, r, x;
		scanf("%lld%lld%lld", &l, &r, &x);
		for(int i=0;i<=62;i++)
			pot[i] = cnt[i] = 0;
		for(ll i=0;i<=62 ;i++){
			if((1ll<<i)&x)  continue;
			pot[i] = 1;
		}
		for(int i =0;i<=62;i++){
			if(i > 0) cnt[i] = cnt[i-1];
			cnt[i] += pot[i];
		}
		res = go(62, r) - go(62, l-1);
	//	printf("RES %lld %lld %lld\n", res, go(62, r), go(62, l-1));
		printf("%lld\n", res);
	}
}
