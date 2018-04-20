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

vector<ll> s[2];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		s[0].clear();
		s[1].clear();
		for(int a=0;a<n;a++){
			ll x;
			scanf("%lld", &x);
			s[a&1].pb(x);
		}
		sort(s[0].begin(), s[0].end());
		sort(s[1].begin(), s[1].end());
		int ans = -1;
		for(int a=1;a<n;a++){
			int t = a&1;
			if(s[t][a/2] < s[1-t][a/2 - 1+t]){
				ans = a-1;
				break;
			}
		}
		printf("Case #%d: ", tt);
		if(ans == -1)
			puts("OK");
		else printf("%d\n", ans);
	}
}
