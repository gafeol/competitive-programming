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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 102;

int n, m, k;
ll dp[MAXN][2][2][11][11][11][11][11], res;

char s[MAXN];

int aa, bb, cc, dd, ee;

inline void put(int a, int b, int c, int d, int e, int x){
	aa = a;
	bb = b;
	cc = c;
	dd = d;
	ee = e;
	if(d < x)
		ee = min(ee, x);
	else if(c < x)
		dd = min(dd, x);
	else if(b < x)
		cc = min(cc, x);
	else if(a < x)
		bb = min(bb, x);
	else{
		aa = min(aa, x);
	}
}


ll go(int i, int lo, int ld, int a, int b, int c, int d, int e){
	ll &r = dp[i][lo][ld][a][b][c][d][e];
	if(r != -1)
		return r;
	if(i == n)
		return r = (e != 10);
	r = 0;
	for(int dig=0;dig<=9;dig++){
		if(!lo && dig > s[i]-'0') break;
		put(a, b, c, d, e, dig);
		if(ld && !dig)
			r = mod(r + go(i+1, max(lo, (int)(dig < s[i]-'0')), 1, a, b, c, d, e));
		else
			r = mod(r + go(i+1, max(lo, (int)(dig < s[i]-'0')), 0, aa, bb, cc, dd, ee));
	}
	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf(" %s", s);
	n = strlen(s);
	s[n-1]--;
	for(int a=n-1;a>=0;a--){
		if(s[a] >= '0') break;	
		s[a-1]--;
		s[a] = '9';
	}
	res = mod(res - go(0, 0, 1, 10, 10, 10, 10, 10));

	memset(dp, -1, sizeof(dp));
	debug("%lld\n", res);
	scanf(" %s", s);
	n = strlen(s);
	res = mod(res + go(0, 0, 1, 10, 10, 10, 10, 10));
	res = mod(res + modn);
	printf("%lld\n", res);
}	
