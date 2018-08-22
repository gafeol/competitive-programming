#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

ll n;
ll mn[2], pos[2];
map<pll, int> res;

int main (){
	scanf("%lld", &n);
	int ok = 0;
	puts("1 1");
	fflush(stdout);
	mn[0] = pos[0] = 1;
	mn[1] = pos[1] = 1;
	int t = 0;
	int cnt= 0;
	while(1){
		int ans;
		if(res.find(pll(pos[0], pos[1])) == res.end())
			scanf("%d", &ans);
		else
			ans = res[pll(pos[0], pos[1])];
		res[pll(pos[0], pos[1])] = ans;
		if(ans == 0) return 0;
		ans--;
		if(ans < 2){
			mn[ans] = pos[ans]+1;
			pos[ans] = (mn[ans] + n)/2ll;
		}
		else{
			pos[t] = (pos[t]+mn[t])/2ll;
			t = 1 - t;
		}
		if(res.find(pll(pos[0], pos[1])) != res.end()) continue;
		if(cnt == 600) assert(false);
		printf("%lld %lld\n", pos[0], pos[1]);	
		cnt++;
		fflush(stdout);
	}
}

