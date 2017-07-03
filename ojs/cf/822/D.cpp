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

const int MAXN = 5000002;

int s[MAXN];
int n, m, k;
int mrk[MAXN];
int sp[MAXN];

ll f(ll x){
	ll cnt = 1;
	ll ans = 0;
	while(x != 1){
		if(!mrk[x])
			sp[x] = x;
		ans = mod(ans + (x*(sp[x]-1))/2ll);
		x /= sp[x];	
	}
	return ans;
}

int main (){
	for(int a=2;a<sqrt(MAXN) + 2;a++){
		if(mrk[a]) continue;
		sp[a] = a;
		for(ll b = a;a*b < MAXN;b++){
			if(!mrk[a*b]){
				mrk[a*b] = 1;
				sp[a*b] = a;
			}
		}
	}
	ll t;
	int l, r;
	scanf("%lld %d %d", &t, &l, &r);
	ll pot = 1;
	ll res = 0;
	for(int i = l; i <= r;i++){
		res = mod(res + pot*f(i));	
		pot  = mod(pot*t);
	}
	printf("%lld\n", res);
}
