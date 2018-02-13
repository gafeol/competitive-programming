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

const int MAXN = 51234, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

ll dp[MAXN];

set<pll> q;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	q.insert(pll(0, 0));
	while(!q.empty()){
		pll top = *q.begin();
		q.erase(q.begin());
		int u = top.snd;
		int d = top.fst;
		for(int a=1;a<n;a++){
			int nxt = (u+s[a])%s[0];
			if(dp[nxt] > d + s[a]){
				if(dp[nxt] != INF)
					q.erase(pll(dp[nxt], nxt));
				dp[nxt] = d + s[a];
				q.insert(pll(dp[nxt], nxt));
			}
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%d", &k);
		if(dp[k%s[0]] <= k)
			puts("TAK");
		else
			puts("NIE");
	}
}

