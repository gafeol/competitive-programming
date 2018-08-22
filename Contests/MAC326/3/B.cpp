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
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		ll sum = 0;
		for(int a=0;a<n;a++){
			scanf("%lld", s+a);
			sum += s[a];
		}
		ll res = 0;
		ll x = sum/n;
		for(int a=0;a<n - k;a++){
			res += abs(s[a] - x);
			s[a + k] += s[a] - x;
		}
		for(int a=n-k;a<n;a++)
			if(s[a] != x)
				res = -1;
		printf("%lld\n", res);
	}
}

