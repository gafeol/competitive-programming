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
ll M;
ll s[MAXN];
ll mx;

int main (){
	scanf("%d%d", &n, &k);
	scanf("%lld", &M);
	ll sum = 0;
	for(int a=0;a<k;a++){
		scanf("%lld", s+a);
		sum += s[a];
	}
	sort(s, s+k);
	mx = 0;
	for(ll c=0;c<=n;c++){
		ll t = 0;
		ll ans = 0;
		t = c*sum;
		ans += c*k + c;
		if(t <= M)
			mx = max(mx, ans);
		for(int i=0;i<k;i++){
			for(int sob = c;sob < n;sob++){
				t += s[i];
				ans++;
				if(t <= M)
					mx = max(mx, ans);
			}
		}
		if(t <= M)
			mx = max(mx, ans);
	}
	printf("%lld\n", mx);
}

