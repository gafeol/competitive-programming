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

const int MAXN = 102, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN], t[MAXN];
char c[MAXN];

int dp[(1<<20)];

bool cmp(int a, int b){
	return a > b;
}

int go(int bm){
	int i = __builtin_popcount(bm);
	debug("go %d %d\n", i, bm);
	int &r = dp[bm];
	if(r != INF)
		return r; 
	if(__builtin_popcount(bm) == m) return r = 0; 
	int T = t[i];
	char C = c[i];

	int ans;
	ans = (T == 1 ? INT_MIN : INT_MAX);
	if(C == 'b'){
		for(int a=0;a<n;a++){
			if((bm&(1<<a))) continue;
			if(T-1)
				ans = min(ans, go(bm|(1<<a)));
			else
				ans = max(ans, go(bm|(1<<a)));
		}
	}	
	else{
		for(int a=0;a<n;a++){
			if((bm&(1<<a))) continue;
			if(T-1)
				ans = min(ans, go(bm|(1<<a)) - s[a]);
			else
				ans = max(ans, go(bm|(1<<a)) + s[a]);
		}
	}
	return r = ans;
}

int main (){
	memset(dp, INF, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	sort(s, s+n, cmp);
	scanf("%d", &m);
	n = min(n, m);
	for(int a=0;a<m;a++)
		scanf(" %c %d", c+a, t+a);
	printf("%d\n", go(0));
}
