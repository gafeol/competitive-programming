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
ll s[MAXN], p[10];
ll k;

ll r[10];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<5;a++)
		scanf("%lld", p+a);
	for(int a=0;a<n;a++){
		k += s[a];
		for(int b=4;b>=0;b--){
			if(k >= p[b]){
				r[b] += k/p[b];
				k = k%p[b];
			}
		}
	}
	for(int a=0;a<5;a++)
		printf("%lld ", r[a]);
	puts("");
	printf("%lld\n", k);
}

