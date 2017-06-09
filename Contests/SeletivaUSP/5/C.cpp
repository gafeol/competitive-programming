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

const int MAXN = 1123;

int n, m, k;
int s[MAXN];
int dp[MAXN][MAXN];
char M[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				scanf(" %c", &M[a][b]);
			}
		}
		for(int a=1;a<=n;a++){
			for(int b=m;b>0;b--){
				if(M[a][b] == '.'){
					dp[a][b] = max(dp[a+1][	
				}
			}
		}
	}
}
