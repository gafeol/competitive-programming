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
const ll INF = 1000000000000000LL;

int n, m, k;
char s[MAXN];
ll c[MAXN];

ll dp[MAXN][5];

char pal[] = {'h', 'a', 'r', 'd'};

ll go(int i, int p){
	ll &r = dp[i][p];

	if(p == 4) 
		return INF;

	if(i == n)
		return r = 0;
	
	if(r != -1)
		return r;
	r = INF;

	r = min(r, go(i+1, p+(pal[p] == s[i])));
	r = min(r, c[i] + go(i+1, p));

	return r;
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	scanf(" %s", s);
	for(int a=0;a<n;a++){
		scanf("%lld", c+a);
	}
	ll res = go(0, 0);
	printf("%lld\n", go(0, 0));
}

