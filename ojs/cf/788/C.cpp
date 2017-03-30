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

const int MAXN = 4123, INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN];
vector<int> s;

int main (){
	int Z = 1005;
	memset(dp, INF, sizeof(dp));
	scanf("%d %d", &k, &n);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		x = x - k;
		s.pb(x);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	dp[Z] = 0;
	int res = INT_MAX;
	for(int a=0;a<s.size();a++){
		debug("com a peça %d:\n\n", s[a]);
		if(s[a] > 0){
			for(int i=0;i<MAXN-s[a];i++){
				if(dp[i] != INF){
					debug("%d -> %d\n", i, i+s[a]);
					assert(i + s[a] < MAXN);
					dp[i+s[a]] = min(dp[i+s[a]], dp[i] + 1);
					if(i+s[a] == Z){
						debug("cheguei no Z com %d\n", dp[i]+1);
						res = min(res, dp[i]+1);
					}
				}
			}
		}
		else{
			for(int i=MAXN-1;i>=-s[a];i--){
				if(dp[i] != INF){
					debug("%d -> %d\n", i, i+s[a]);
					assert(i + s[a] >= 0);
					dp[i+s[a]] = min(dp[i+s[a]], dp[i] + 1);
					if(i+s[a] == Z){
						debug("cheguei no Z com %d\n", dp[i]+1);
						res = min(res, dp[i]+1);
					}
				}
			}
		}
	}
	if(res != INT_MAX)
		printf("%d\n", res);	
	else
		puts("-1");
}
