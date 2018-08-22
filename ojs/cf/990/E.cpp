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

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];

int bef[MAXN];

int mrk[MAXN];
int prv[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
		int x;
		scanf("%d", &x);
		mrk[x] = 1;
	}
	mrk[n] = 1;
	if(mrk[0]){
		int x;
		for(int a=0;a<k;a++){
			scanf("%d", &x);
		}
		puts("-1");
		return 0;
	}
	prv[0] = 0;
	for(int a=1;a<=n;a++){
		prv[a] = prv[a-1];
		if(!mrk[a])
			prv[a] = a;
	}
	ll ans = LLONG_MAX;
	for(int a=1;a<=k;a++){
		ll cus;
		scanf("%lld", &cus);
		ll res = 0;
		int i = 0;
		while(i < n){
			res += (ll)cus;
			// i valido
			if(i + a >= n) break; 
			if(i == prv[i+a]){
				res = LLONG_MAX;
				break;
			}
			i = prv[i+a];
		}
		ans = min(ans, res);
	}

	if(ans == LLONG_MAX)
		puts("-1");
	else
		printf("%lld\n", ans);
}

