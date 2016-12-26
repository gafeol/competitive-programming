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

const int MAXN = 212345, LOGN = 35;

int n, m, k;
int s[MAXN], p[MAXN][LOGN];
int cnt[MAXN], res[MAXN];
ll w[MAXN][LOGN];
vector<int> adj[MAXN];

void go(int u){
	for(int i=1;i<LOGN;i++){
		p[u][i] = p[p[u][i-1]][i-1];
		w[u][i] = w[p[u][i-1]][i-1] + w[u][i-1];
	}
	int uu = u;
	int S = 0;
	for(int a=LOGN-1;a>=0;a--){
		if(S + w[uu][a] <= s[u]){
			S += w[uu][a];
			uu = p[uu][a];
		}
	}
	cnt[p[uu][0]] -= 1;
	cnt[p[u][0]] += 1;
	for(int nxt: adj[u]){
		go(nxt);
		cnt[u] += cnt[nxt];
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=2;a<=n;a++){
		scanf("%d%lld", &p[a][0], &w[a][0]);
		adj[p[a][0]].pb(a);
	}
	go(1);
	for(int i=1;i<=n;i++){
		printf("%d ", cnt[i]);
	}

}
