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

const int MAXN = 102;

int n, m;
int dp[MAXN][MAXN][27][2];

vector<int> adj[MAXN];
vector<int> ch[MAXN];

int go(int i, int j, int ci, int t){
	int &r = dp[i][j][ci][t];	
	if(r != -1) return r;
	if(t == 0){
		for(int a=0;a<adj[i].size();a++){
			int nxt = adj[i][a];
			int c = ch[i][a];
			if(c >= ci)
				if(go(nxt, j, c, 1-t) == 0)
					return r = 1;
		}
		return r = 0;
	}
	else{
		for(int a=0;a<adj[j].size();a++){
			int nxt = adj[j][a];
			int c = ch[j][a];
			if(c >= ci)
				if(go(i, nxt, c, 1-t) == 0)
					return r = 1;
		}
		return r = 0;
	}
}

int main (){
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<m;a++){
		int i, j;
		char c;
		scanf("%d %d %c", &i, &j, &c);
		i--;
		j--;
		adj[i].pb(j);
		ch[i].pb((c-'a'));
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			printf("%c", 'A'+1-go(a, b, 0, 0));
		}
		puts("");
	}
}

