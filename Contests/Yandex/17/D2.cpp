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

const int MAXN = 1000006, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int dp[MAXN][4];

int go(int i, int bm){
	int &r = dp[i][bm];
	int bef = ((bm&2) != 0);
	if(r != -1)
		return r;
	if(i == n){
		if((s[i-1]^bef) == 0)
			return r = 0;
		else
			return r = INF;
	}
	r = INF;
	int nxt = ((bm<<1)&3);
	if(i == 0){
		r = min(r, go(i+1, (nxt^3)) + 1);
		r = min(r, go(i+1, nxt));
		return r;
	}
	
	if((bef^s[i-1]) == 1){
		return r = min(r, go(i+1, (nxt^3)) + 1);
	}
	
	r = min(r, go(i+1, nxt));
	return r;
}

int main (){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		s[a] = !(s[a]&1);
	}
	int res = go(0, 0);
	if(res == INF)
		res = -1;
	printf("%d\n", res);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		s[a] = (!s[a]);
	}
	res = go(0, 0);
	if(res == INF)
		res = -1;
	printf("%d\n", res);
}
