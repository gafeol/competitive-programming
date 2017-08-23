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

const int MAXN = 312345;

int n, m, k;
int s[MAXN], mrk[MAXN];
int cnt[MAXN], tempo;

vector<pii> adj[MAXN];
vector<int> res;

int go(int u){
	mrk[u] = 1;
	cnt[u] = 0;
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		int i = ar.snd;
		if(mrk[nxt]) continue;
		go(nxt);	
		if(s[nxt] != -1 && (cnt[nxt]&1) != s[nxt]){
			res.pb(i);
			cnt[nxt]++;
			cnt[u]++;
		}
	}
}

int vis[MAXN];
int zr, um;

void dfs(int u){
	vis[u] = tempo;
	if(s[u] == 0)
		zr = u;
	if(s[u] == 1)
		um = u;
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		if(vis[nxt] == tempo) continue;
		dfs(nxt);
	}
}

void tenta(int u){
	vis[u] = tempo;
	cnt[u] = 0;
	for(pii ar: adj[u]){
		int nxt = ar.fst;
		int i = ar.snd;
		if(vis[nxt] == tempo) continue;
		tenta(nxt);	
		if(s[nxt] != -1 && (cnt[nxt]&1) != s[nxt]){
			cnt[nxt]++;
			cnt[u]++;
		}
	}
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);	
		i--;j--;
		adj[i].pb(pii(j, a));
		adj[j].pb(pii(i, a));
	}
	for(int a=0;a<n;a++){
		if(s[a] == -1){
			if(!mrk[a])
				go(a);
		}
	}
	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		int S = -1;
		zr = -1;
		um = -1;
		tempo++;
		dfs(a);
		if(zr != -1){
			tempo++;
			tenta(zr);
			if((cnt[zr]&1) == s[zr])
				S = zr;
		}
		if(um != -1){
			tempo++;
			tenta(um);
			if((cnt[um]&1) == s[um])
				S = um;
		}
		if(S == -1){
			puts("-1");
			return 0;
		}
		go(S);
	}
	printf("%d\n", (int)res.size());
	for(int ar: res){
		printf("%d\n", ar+1);
	}
}
