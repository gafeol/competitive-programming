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
int s[MAXN];
ll pot[MAXN];

int main (){
	pot[0] = 1;
	for(int a=1;a<MAXN;a++){
		pot[a] = mod(pot[a-1]*2ll);
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n);
	ll res =0;
	for(int a=0;a<n;a++){
		if(n - a - 1 >=  0){
			res = mod(res - s[a]*(pot[n-a-1] - 1));
		}
	}
	debug("%lld\n", res);
	for(int a=n-1;a>=0;a--){
		if(a  >= 0)
			res = mod(res + s[a]*(pot[a] - 1));
	}
	debug("%lld\n", res);
	res = mod(res + modn);
	printf("%lld\n", res);
}
