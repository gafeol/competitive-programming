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
int s[MAXN];
int pre[MAXN], suf[MAXN];
ll som;

int main (){

	for_tests(t, tt){
		scanf("%d", &n);
		pre[0] = 0;
		suf[n+1] = 0;
		som = 0;
		for(int a=1;a<=n;a++){
			scanf("%d", &s[a]);
			som += s[a];
		}
		for(int a=1;a<=n;a++){
			pre[a] = min(pre[a-1]+1, s[a]);
			debug("pre[%d] %d\n", a, pre[a]);
		}
		for(int a=n;a>=1;a--){
			suf[a] = min(suf[a+1]+1, s[a]);
			debug("suf[%d] %d\n", a, suf[a]);
		}
	
		ll mx = 0;
		for(int a=1;a<=n;a++){
			mx = max(mx, (ll)min(pre[a], suf[a]));
		}
		printf("%lld\n", som - ((mx + 1)*mx) + mx);
	}
}
