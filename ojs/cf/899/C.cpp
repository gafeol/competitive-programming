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

ll n, m, k;
int s[MAXN];

vector<int> res;

int main (){
	scanf("%lld", &n);
	ll sum = ((n+1)*n)/2ll;
	printf("%lld\n", (sum&1));
	sum = sum/2ll;
	for(ll a = n;a>=1;a--){
		if(sum >= a){
			sum -= a;
			res.pb(a);
		}
	}
	printf("%d ", (int)res.size());
	for(int x: res){
		printf("%d ", x);
	}
	puts("");
}

