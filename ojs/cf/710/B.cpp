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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN], su[MAXN];

int main (){
	scanf("%d", &n);
	ll sum = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		sum += s[a];
	}
	sort(s, s+n);
	ll res = LLONG_MAX;
	int ir = 0;
	for(int a=0;a<n;a++){
		debug("tst %lld - %lld -(%lld)*%lld = %lld\n", sum, su[a], (ll)(n-a), s[a], sum - su[a] - (n-2*a)*s[a]);
		if(res > sum - su[a] - (n-2*a)*s[a]){
			res = sum - su[a] - (n-a*2)*s[a];
			ir = s[a];
		}
		su[a+1] = su[a];
		su[a+1] += s[a];
		sum -= s[a];
	}
	printf("%d\n", ir);
}
