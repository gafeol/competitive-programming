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
ll v[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	ll mx = LLONG_MIN;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<m;a++){
		scanf("%lld", v+a);
	}
	int imx;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			mx = max(mx, s[a]*v[b]);
			if(mx == s[a]*v[b])
				imx = a;
		}
	}
	mx = LLONG_MIN;
	for(int a=0;a<n;a++){
		if(a == imx) continue;
		for(int b=0;b<m;b++){
			mx = max(mx, s[a]*v[b]);
		}
	}
	printf("%lld\n", mx);

}

