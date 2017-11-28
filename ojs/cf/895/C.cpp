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

const int MAXN = 1123456, LOGN = 20;

int n, m, k;
int s[MAXN];

vector<int> pri;

int f(int x){
	int ans = 0;
	for(int i  =0;i < pri.size();i++){
		int p = pri[i];
		while(x % p == 0){
			x /= p;
			ans ^= (1<<i);
		}
	}
	return ans;
}

ll dp[2][MAXN], ps[2][MAXN], cnt[MAXN];
int mrk[100];

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);
	if(e&1) ans = mod(ans*base);
	return ans;
}

int main (){
	for(int a=2;a<=70;a++){
		if(mrk[a]) continue;
		pri.pb(a);
		for(int b=a;b*a <= 70;b++)
			mrk[a*b] = 1;
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] = f(s[a]);
		cnt[s[a]]++;
	}
	int t = 0;
	dp[0][0] = expo(2, cnt[0]);
	for(int x=1;x<MAXN;x++){
		if(cnt[x] == 0) continue;
		for(int a=0;a<MAXN;a++){
			dp[t^1][a] = 0;
			ps[t^1][a] = 0;
		}
		for(int a=0;a<MAXN;a++){
			if(dp[t][a] == 0 || ps[t][a]) continue;	
			ll som = mod(dp[t][a] + dp[t][a^x]);
			ps[t][a^x] = 1;
			debug("som %lld de %d e %d\n", som, a, a^x);
			ll val = mod(som*expo(2, cnt[x]-1));
			debug("val %lld cnt[%d] %lld\n", val, x, cnt[x]);
			dp[t^1][a] = mod(dp[t^1][a] + val);
			dp[t^1][a^x] = mod(dp[t^1][a^x] + val);
		}
		t = t^1;
		for(int a=0;a<10;a++)
			debug("%lld ", dp[t][a]);
		puts("");
	}
	printf("%lld\n", dp[t][0] - 1); 
}
