#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 200005;

int n, m, k;
int s[MAXN];
ll mrk[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n);
	mrk[MAXN-1] = 0;
	int i = n-1, j = MAXN-2;
	while(j >= 0){
		mrk[j] = mrk[j+1];
		while(i >= 0 && s[i]==j){
			mrk[j]++;
			i--;
		}
		j--;
	}
	ll ans = LLONG_MIN;
	for(int a=0;a<n;a++){
		ll res = 0;
		if(a == 0 || s[a] != s[a-1]){
			ll b;
			for(b=1;(b+1)*s[a]<MAXN;b++){
				res += (mrk[b*s[a]] - mrk[(b+1)*s[a]])*(b*s[a]);
			}
			res += mrk[b*s[a]]*(b*s[a]);
		}
		ans = max(ans, res);
		debug("%d res %lld\n", a, res);
	}
	printf("%lld\n", ans);
}
