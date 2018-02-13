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

const int MAXN = 2123456;

ll n, m, k;
int s[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%lld%lld", &k, &n);
		ll sum = (n*(n+1ll))/2ll - k;
		if((sum&1)){
			puts("impossible");
			continue;
		}
		memset(s, 0, sizeof(s));
		sum = sum/2ll;
		for(ll i=n;i>=1;i--){
			if(i == k) continue;
			if(sum >= i){
				if(k <= 2 && sum - i == k) continue;
				s[i] = 1;
				sum -= i;
			}
		}
		s[k] = 2;
		if(!sum){
			for(int a=1;a<=n;a++)
				printf("%d", s[a]);
			puts("");
		}
		else
			puts("impossible");
	}
}
