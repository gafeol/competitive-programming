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
ll k;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", &k);
		ll i = 1, j = k;
		while(i < j){
			ll m = (i + j + 1)/2;
			if((m*(m-1))/2 <= k-m)
				i = m;
			else
				j = m-1;
		}
		printf("%lld\n", max(2*(k-i-1), (i*(i-1))/2 + k-i));
	}
}
