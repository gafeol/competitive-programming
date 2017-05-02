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

inline ll mod(ll x) { 
	while(x < 0)
		x += modn;
	return x % modn; 
}

const int MAXN = 212345;

int n, m, k;
char s[2][MAXN];

ll h[2][MAXN];

unordered_map<int, pii> ind[MAXN];

inline ll l(char c){
	return (ll)(c - 'a');
}

ll expo(ll base, ll e){
	if(e == 0) return 1;

	ll ans = expo(base, (e>>1));
	ans = mod(ans*ans);

	if(e&1)
		ans = mod(ans*base);
	
	return ans;
}

int main (){
	scanf(" %s %s", s[0]+1, s[1]+1);

	n = strlen(s[0]+1);
	m = strlen(s[1]+1);

	for(int a=0;a<2;a++){
		h[a][0] = 0;
		for(int i = 1;i <= (a == 0 ? n:m);i++){
			
			h[a][i] = mod(mod(h[a][i-1]*26) + l(s[a][i]));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll hash = mod(h[0][j] - mod(h[0][i-1]*expo(26, j-i+1))); 
			ind[j-i][hash].fst++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			ll hash = mod(h[1][j] - mod(h[1][i-1]*expo(26, j-i+1)));
			ind[j-i][hash].snd++;
		}
	}
	int res = INT_MAX;
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			ll hash = mod(h[1][j] - mod(h[1][i-1]*expo(26, j-i+1)));
			if(ind[j-i][hash] == pii(1, 1))
				res = min(res, j - i + 1);
		}
	}
	if(res == INT_MAX)
		res = -1;
	printf("%d\n", res);
}
