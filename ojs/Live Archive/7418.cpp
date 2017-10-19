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

const int MAXN = 2123;
const ll INF = 11234567890123LL;

int n, m;
ll k;
char s[MAXN];

ll mn[MAXN][MAXN];

ll dp[MAXN][MAXN];

vector<char> ans;

int tam;

void init(){
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			mn[a][b] = INF;
			dp[a][b] = -1;
		}
	}
}

ll sz(int i, int j){
	if(i >= j)
		return mn[i][j] = (i == j);

	if(mn[i][j] != INF) return mn[i][j];

	if(s[i] == s[j])
		return mn[i][j] = min(mn[i][j], sz(i+1, j-1) + 2ll);	
	
	mn[i][j] = min(mn[i][j], sz(i+1, j) + 2ll);
	mn[i][j] = min(mn[i][j], sz(i, j-1) + 2ll);

	return mn[i][j];
}

ll go(int i, int j, int tam){
	if(i >= j)
		return dp[i][j] = 1;
	
	if(dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 0;

	if(s[i] == s[j] && tam == 2ll+sz(i+1, j-1))
		return dp[i][j] = min((ll)1e18, dp[i][j] + go(i+1, j-1, tam-2));
	if(tam == 2ll+sz(i+1, j))
		dp[i][j] = min((ll)1e18, dp[i][j] + go(i+1, j, tam-2));
	if(tam == 2ll+sz(i, j-1))
		dp[i][j] = min((ll)1e18, dp[i][j] + go(i, j-1, tam-2));

	debug("dp[%d][%d] %lld\n", i, j, dp[i][j]);
	return dp[i][j];
}

void re(int i, int j, int tam){
	if(i == j)
		ans.pb(s[i]);
	if(i >= j) return;

	if(s[i] == s[j] && tam == 2+sz(i+1, j-1)){
		ans.pb(s[i]);
		return re(i+1, j-1, tam-2);
	}

	if(s[i] < s[j]){
		debug("%c < %c\n", s[i], s[j]);
		debug("tam %d == 2 + %lld && %lld > go(%d, %d) %lld\n", tam, sz(i, j-1), k, i+1, j, go(i+1, j, tam-2));
		if(tam == 2 + sz(i, j-1) && k > go(i+1, j, tam-2)){
			k -= go(i+1, j, tam-2);
			ans.pb(s[j]);
			re(i, j-1, tam-2);
		}
		else{
			assert(tam == 2ll + sz(i+1, j));
			ans.pb(s[i]);
			re(i+1, j, tam-2);
		}
	}
	else{
		debug("%c > %c\n", s[i], s[j]);
		debug("%lld > go(%d %d) %lld\n", k, i, j-1, go(i, j-1, tam-2));
		if(tam == 2 + sz(i+1, j) && k > go(i, j-1, tam-2)){
			k -= go(i, j-1, tam-2);
			ans.pb(s[i]);
			re(i+1, j, tam-2);
		}
		else{
			assert(tam == 2ll + sz(i, j-1));
			ans.pb(s[j]);
			re(i, j-1, tam-2);
		}
	}
}

int main (){
	while(scanf(" %s", s) != EOF){
		ans.clear();
		scanf("%lld", &k);
		n = strlen(s);
		init();
		tam = sz(0, n-1);	
		debug("tam %d\n", tam);
		go(0, n-1, tam);
		re(0, n-1, tam);
		if(k != 1){
			puts("NONE");
			continue;
		}
		for(int a=0;a<ans.size();a++)
			printf("%c", ans[a]);
		for(int a=ans.size()-1-(tam&1);a>=0;a--)
			printf("%c", ans[a]);
		puts("");
	}
}
