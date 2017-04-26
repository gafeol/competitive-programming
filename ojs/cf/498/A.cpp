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

int n, m;
int s[MAXN];

int sig(ll i, ll j, ll k, ll x, ll y){
	return ((i*x + j*y + k) > 0);
}

int main (){
	int x, y, xx, yy;
	scanf("%d%d%d%d", &x, &y, &xx, &yy);
	scanf("%d", &n);
	int res =0;
	for(int a=0;a<n;a++){
		ll i, j, k;
		scanf("%lld %lld %lld", &i, &j, &k);	
		if(sig(i, j, k, x, y) != sig(i, j, k, xx, yy))
			res++;
	}
	printf("%d\n", res);
}
