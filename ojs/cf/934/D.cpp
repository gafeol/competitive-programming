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


ll r, k;
int s[MAXN];

vector<ll> ans;

int main (){
	scanf("%lld%lld", &r, &k);
	int st = 10000000;
	while((r >= k || r < 0) && st--){
		ll d;
		if(r > k)
			d = -r/k;
		else
			d = -r/k + (r%k != 0);
		ans.pb(r + d*k);
		r = d;
	}
	if(r != 0)
		ans.pb(r);
	if(st <= 0){
		puts("-1");
		return 0;
	}
	else{
		printf("%d\n", (int)ans.size());
		for(int a=0;a<ans.size();a++){
			printf("%lld ", ans[a]);
		}
	}
}

