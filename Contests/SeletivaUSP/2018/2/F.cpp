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

const int MAXN = 105;

int n, m, k;

int dp[MAXN][MAXN][MAXN];
bool in[MAXN][MAXN][MAXN];
pii s[MAXN];

vector<int> adj[MAXN];

inline bool isin(int c, int a, int b){
	int dx = abs(s[a].fst - s[b].fst);
	if(dx == 0) return (s[c].snd >= s[a].snd && s[c].snd <= s[b].snd);
	int mxy = k/dx;
	if(s[c].snd > mxy) return false;
	if(s[c].fst < min(s[a].fst, s[b].fst) || s[c].fst > max(s[a].fst, s[b].fst)) return false;
	return true;
}

int go(int u, int i, int j){
	// ult = (i, j+1)
	int &r = dp[u][i][j];
	if(r != -1) return r;
	if(u > j) return r = 0;
	r = INT_MAX;
	if(in[u][i][j+1])
		return r = go(u+1, i, j);
	for(int nxt: adj[u]){
		if(nxt > j) break;
		r = min(r, 1 + go(u+1, u, nxt-1) + go(nxt+1, i, j));
	}
	return r;
}

int main (){
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	for(int a=1;a<=n;a++)
		scanf("%d %d", &s[a].fst, &s[a].snd);
	sort(s+1, s+n+1);
	for(int a=1;a<=n;a++){
		for(int b=a;b<=n;b++){
			if(((ll)max(s[a].snd, s[b].snd))*((ll)s[b].fst - s[a].fst) > (ll)k)
				continue;
			adj[a].pb(b);
			for(int c=a;c<=b;c++)
				in[c][a][b] = isin(c, a, b);
		}
	}
	printf("%d\n", go(1, 0, n)); 
}

