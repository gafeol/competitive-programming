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

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll p, q, b;
		scanf("%lld %lld %lld", &p, &q, &b);
		ll md = gcd(p, q);
		p = p/md;
		q = q/md;
		while((md = gcd(q, b)) != 1){
			while(q%md == 0)
				q/=md;
		}
		if(b%q == 0)
			puts("Finite");
		else
			puts("Infinite");
	}
}

