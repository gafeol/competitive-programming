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

const int MAXN = 1502, INF = 0x3f3f3f3f;

int n, m, k;
char st[MAXN];
int s[MAXN];
int dp[27][MAXN][MAXN];
int memo[27][MAXN];

int main (){
	scanf("%d", &n);
	scanf(" %s", st);
	for(int a=0;a<n;a++){
		s[a] = (st[a] - 'a');
	}

	for(int tam=0;tam<n;tam++){
		for(int i=0;i<n-tam;i++){
			for(int c=0;c<26;c++){
				if(tam == 0)
					dp[c][i][i+tam] = (s[i] != c);
				else
					dp[c][i][i+tam] = (s[i] != c) + dp[c][i+1][i+tam];
				memo[c][dp[c][i][i+tam]] = max(memo[c][dp[c][i][i+tam]], tam+1);
			}

		}
	}
	for(int c=0;c<26;c++){
		for(int i=1;i<=n;i++){
			memo[c][i] = max(memo[c][i], memo[c][i-1]);
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		char ch;
		scanf(" %d %c", &k, &ch);
		printf("%d\n", max(k, memo[(ch-'a')][k]));
	}
}
