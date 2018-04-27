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

multiset<pii> q;  

int main (){
	scanf("%d%d", &n, &k);
	for(int a=1;a<n;a++){
		scanf("%d", s+a);
	}
	ll sum = 0;
	for(int a=1;a<=k;a++){
		sum += (ll)s[a];
	}
	ll mn = LLONG_MAX;
	for(int a=1;a+k<=n;a++){
		mn = min(sum, mn);	
		sum -= s[a];
		sum += s[a+k];
	}
	printf("%lld\n", mn);
}

