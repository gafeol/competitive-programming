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

int main (){
	scanf("%d%d", &n, &k);

	ll res = 0;
	ll mult = 1;
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	int b = 0;
	ll som = 0;
	for(int a=0;a<n;a++){
		while(b < n && b < a + k){
			som += s[b];
			b++;
		}
		if(b < a + k) break;
		res += som;
		som -= s[a];
	}
	double ans = res;
	printf("%.10f\n", ans/(n - k + 1));
}
