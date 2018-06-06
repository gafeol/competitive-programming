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

const int MAXN = 112, INF = 0x3f3f3f3f, IMP = -INF +1100000;

int n, m, k;
int s[MAXN];
int nxt[MAXN], son[MAXN];
int dp[MAXN][MAXN][3];
ll cnt[MAXN][MAXN][3];

vector<int> adj[MAXN];

void dfs(int u, int p){
	int ult = n;
	int fst = -1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		::nxt[ult] = nxt;	
		if(fst == -1)
			fst = nxt;
		dfs(nxt, u);
		ult = nxt;
	}
	son[u] = fst;
}


int go(int u, int k, int lst){
	if(dp[u][k][lst] != -INF) return dp[u][k][lst];

	int &r = dp[u][k][lst];
	if(k == 0) return r = 0;
	if(son[u] == -1 && nxt[u] == -1){
		if(k == 1)
			return r = s[u];
		else
			return r = IMP;
	}
	if(son[u] == -1){
		if(k == 1)
			r = max(r, s[u]);
		r = max(r, go(nxt[u], k, lst));
		if(lst && k != 1)
			r = max(r, s[u] + go(nxt[u], k-1, lst));
		return r;
	}
	if(nxt[u] == -1){
		r = max(r, go(son[u], k-1, 1) + s[u]);
		if(!lst)
			r = max(r, go(son[u], k, 0));
		return r;
	}
	
	r = max(r, go(nxt[u], k, lst));
	r = max(r, go(son[u], k-1, 1) + s[u]);
	if(!lst) r = max(r, go(son[u], k, lst));
	if(lst){
		for(int a=1;a<k;a++)
			r = max(r, s[u] + go(son[u], a-1, 1) + go(nxt[u], k-a, 1));
	}
	return r;
}

int res = 0;

ll count(int u, int k, int lst, int sum){
	assert(go(u, k, lst) + sum == res);
	if(cnt[u][k][lst] != -INF) return cnt[u][k][lst];
	ll &r = cnt[u][k][lst];
	r = 0;
	if(k == 0){ 
		if(sum == res) return r = 1;
		else return r = 0;
	}
	if(son[u] == -1 && nxt[u] == -1){
		//if(sum + go(u, k, lst) == res)
		if(k == 1 && sum + s[u] == res){
			//printf("%d %d %d %d = 1\n", u, k, lst, sum);
			return r = 1;
		}
		else
			return r = 0;
	}
	if(son[u] == -1){
		if(k == 1 && sum + s[u] == res)
			r = mod(r + 1);
		if(sum + go(nxt[u], k, lst) == res)
			r = mod(r + count(nxt[u], k, lst, sum));
		if(lst && k != 1 && sum + go(nxt[u], k-1, lst) + s[u] == res)
			r = mod(r + count(nxt[u], k-1, lst, sum + s[u]));
		return r;
	}
	if(nxt[u] == -1){
		if(sum + go(son[u], k-1, 1) + s[u] == res)
			r = mod(r + count(son[u], k-1, 1, sum + s[u]));
		if(!lst && sum + go(son[u], k, 0) == res)
			r = mod(r + count(son[u], k, 0, sum));
		return r;
	}
	
	if(sum + go(nxt[u], k, lst) == res)
		r = mod(r + count(nxt[u], k, lst, sum));
	if(sum + s[u] + go(son[u], k-1, 1) == res)
		r = mod(r + count(son[u], k-1, 1, sum + s[u]));
	if(!lst && sum + go(son[u], k, lst) == res)
		r = mod(r + count(son[u], k, lst, sum));
	if(lst){
		for(int a=1;a<k;a++){
			if(go(nxt[u], k-a, 1) + go(son[u], a-1, 1) + sum + s[u] == res)
				r = mod(r + count(son[u], a-1, 1, sum + s[u] + go(nxt[u], k-a, 1)) *
						    count(nxt[u], k-a, 1, sum + s[u] + go(son[u], a-1, 1)));
		}
	}
	return r;
}

int main (){
	for_tests(t, tt){
		scanf("%d%d%d", &n, &k, &m);
		assert(m == n-1);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			nxt[a] = -1;
			son[a] = -1;
		}
		for(int a=0;a<=n;a++){
			for(int b=0;b<=k;b++){
				for(int c=0;c<2;c++){
					dp[a][b][c] = -INF;
					cnt[a][b][c] = -INF;
				}
			}
		}
		for(int a=0;a<n;a++)
			scanf("%d", s+a);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].pb(j); adj[j].pb(i); 
		}
		dfs(0, 0);
		res = go(0, k, 0);
		printf("%d %lld\n", res, count(0, k, 0, 0));
		/*for(int a=0;a<n;a++){
			for(int b=0;b<=k;b++){
				for(int c=0;c<2;c++){
					printf("cnt[%d][%d][%d] %d\n", a, b, c, cnt[a][b][c]);
				}
			}
		}
		*/
	}
}

