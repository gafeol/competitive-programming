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

const int MAXN = 510;

int n, m, k;
int s[MAXN];

bitset<510> chega[510][62][2];

ll dp[510][62][2];

ll go(int i, int k, int t){
	if(k == -1) return 0;
	ll &r = dp[i][k][t];
	
	if(r != -1) return r;

	r = max(r, go(i, k-1, t));
	for(int j=1;j<=n;j++){
		if(chega[i][k][t][j])
			r = max(r, go(j, k-1, t^1) + (1ll<<k));	
	}
	r = min(r, (ll)1e18 + 1ll);
	return r;
}

int main (){
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<m;a++){
		int i, j, t;
		scanf("%d %d %d", &i, &j, &t);
		chega[i][0][t].set(j);
	}
	for(int k = 1;k < 61;k++){
		for(int t = 0;t<2;t++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(chega[i][k-1][t][j]){
						chega[i][k][t] |= chega[j][k-1][t^1];
					}
				}
			}
		}
	}
	ll res = 0;
	for(int i=1;i<=n;i++){
		res = max(res, go(i, 60, 0));
	}
	if(res > 1e18L){
		puts("-1");
		return 0;
	}
	printf("%lld\n", res);
}
