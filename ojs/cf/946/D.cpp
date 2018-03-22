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

const int MAXN = 512, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN][MAXN];
int bst[MAXN][MAXN];
int dp[MAXN][MAXN];

vector<int> cl[MAXN];

int go(int i, int k){
	if(i == n) return 0;
	int &r = dp[i][k];
	if(r != -1) return r;
	r = INF;
	for(int a=0;a<=k;a++){
		r = min(r, go(i+1, k-a) + bst[i][a]);
	}
	return r;
}

int main (){
	memset(bst, INF, sizeof(bst));
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		char c;
		for(int b=0;b<m;b++){
			scanf(" %c", &c);
			s[a][b] = (c == '1');
			if(c=='1')
				cl[a].pb(b);
		}
	}
	for(int a=0;a<n;a++){
		for(int i=0;i<cl[a].size();i++){
			for(int j=cl[a].size()-1;j>=i;j--){
				bst[a][i+(cl[a].size()-j-1)] = min(bst[a][i+(cl[a].size()-1-j)], cl[a][j] - cl[a][i] + 1);
			}
		}
		for(int i=cl[a].size();i<MAXN;i++)
			bst[a][i] = 0;
	}
	printf("%d\n", go(0, k));
}

