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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
ll l;
ll s[MAXN];

int main (){
	scanf("%d%d%lld", &n, &k, &l);
	for(int a=0;a<n*k;a++){
		scanf("%lld", s+a);
	}
	sort(s, s+n*k);
	ll ans = 0;
	int cnt = 0;
	ans += s[0];
	cnt = 1;
	int lst = 0;
	while(lst < n*k && s[lst] - s[0] <= l) lst++;

	lst--;
	if(lst+1<n){
		puts("0");
		return 0;
	}
	for(int a=1;a<n*k;a++){
		if(cnt == n) break;
		int sob = lst - a;
		if(a+1 > cnt*k){
			debug("obriga a pegar %lld\n", s[a]);
			cnt++;
			ans += s[a];
			continue;
		}
		debug("sob %d\n", sob);
		if(sob >= n - cnt){
			debug("pode pular %lld\n", s[a]);
			continue;
		}
		debug("pega %lld\n", s[a]);
		cnt++;
		ans += s[a];
	}
	printf("%lld\n", ans);
}

