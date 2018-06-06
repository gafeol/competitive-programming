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

vector<pii> ev[MAXN];

int dp[MAXN];

void add(int t, pii x){
	int val = x.snd;
	int mx = x.fst; 
	for(int a=n-val;a>=0;a--){
		if(dp[a] >= t){
			dp[a+val] = max(dp[a+val], min(dp[a], mx));	
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		ev[i].pb(pii(j, k));
	}
	dp[0] = n;
	for(int a=1;a<=n;a++){
		for(pii e: ev[a]){
			add(a, e);
		}
	}
	vector<int> ans;
	for(int a=1;a<=n;a++){
		if(dp[a] > 0)
			ans.pb(a);
	}
	printf("%d\n", (int)ans.size());
	for(int x: ans){
		printf("%d ", x);
	}
	puts("");
}

