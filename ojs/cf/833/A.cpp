
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
int mrk[MAXN];

vector<ll> p;

int main (){
	for(ll a=2;a<=sqrt(1e9);a++){
		if(mrk[a]) continue;
		p.pb(a);
		for(ll b=a;a*b < MAXN;b++){
			mrk[a*b] = 1;
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll i, j;
		scanf("%lld %lld", &i, &j);
		if(i == j && i == 1){
			puts("Yes");
			continue;
		}
		ll mult = i*j;
		ll c = cbrt((double)mult) + (double)0.5;
		if(c*c*c != mult){
			puts("No");
			continue;
		}
		if(i%c != 0 || j%c != 0){
			puts("No");
			continue;
		}
		puts("Yes");

	}
}

