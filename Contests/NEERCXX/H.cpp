
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
ll s[MAXN];
ll pre[MAXN], suf[MAXN], pp[MAXN], ps[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
		pre[a] = s[a];
		pre[a] = max(pre[a], pre[a-1]+1);
		pp[a] = pp[a-1] + pre[a] - s[a]; 
	}
	for(int a=n;a>=1;a--){
		suf[a] = s[a];
		suf[a] = max(suf[a], suf[a+1]+1);
		ps[a] = ps[a+1] + suf[a] - s[a];
	}
	ll res = LLONG_MAX;
	for(int a=1;a<=n;a++){
		ll ans = 0;
		if(pre[a] < suf[a])
			ans = pp[a-1] + ps[a];
		else
			ans = pp[a] + ps[a+1];
		res = min(res, ans);
	}
	printf("%lld\n", res);
}

