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

ll n, k;
int s[MAXN];

int main (){
	scanf("%lld%lld", &n, &k);
	ll res = 1;
	if(k > 1)
		res += (n*(n-1))/2;
	if(k > 2)
		res += (n*(n-1)*(n-2))/3ll;
	if(k > 3)
		res += ((n*(n-1)*(n-2)*(n-3))/(2*3*4ll))*9;
	printf("%lld\n", res);
}

