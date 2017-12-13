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
ll s[MAXN], sum[MAXN];

ll w, h;

int main (){
	scanf("%d%lld%lld", &n, &w, &h);
	ll S = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		sum[a] = s[a];
		if(a != 0)
			sum[a] += sum[a-1];
		S += s[a];
	}
	for(int a=0;a<n;a++){
		s[n+a] = s[a];
		sum[n+a] = sum[n+a-1] + s[a];
	}
	S += n;
	int cnt = 1;
	dp[0] = 0;
	int u = 0;
	while(dp[nxt] 
	ll ans = w/S; 
	ll sob = w - (w/S)*S;
	int i = u, j = u+n-1;
	int pre = 0;
	if(u != 0)
		pre = sum[u-1];
	while(i < j){
		int m = (i + j + 1)/2;
		if(sum[m] - pre + (m - u) > sob)
			j = m-1;
		else
			i = m;
	}
	nxt = i;
	if(nxt < u)
		ans++;
	
}

