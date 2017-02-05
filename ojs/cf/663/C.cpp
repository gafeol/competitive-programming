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

int n, m, k;
int s[MAXN];
int mrk[MAXN];
int cor[MAXN];
int fodeu[2];

vector<pii> adj[MAXN];

vector<int> res[2], cnt[2];

void go(int u, int c){
	debug("%d %d\n", u, c);
	mrk[u] = 1;
	for(pii nxt: adj[u]){
		if(mrk[nxt.fst]){
			if(nxt.snd == c && cor[u] != cor[nxt.fst])
				fodeu[c] = 1;
			else if(nxt.snd == 1-c && cor[u] == cor[nxt.fst])
				fodeu[c] = 1;
			continue;
		}
		if(nxt.snd == c){
			cnt[cor[u]].pb(nxt.fst);	
			cor[nxt.fst] = cor[u];
			go(nxt.fst, c);
		}
		else{
			cor[nxt.fst] = 1-cor[u];
			cnt[cor[nxt.fst]].pb(nxt.fst);
			go(nxt.fst, c);
		}
	}
}

void print(int x){
	printf("%d\n", (int)res[x].size());
	for(int u: res[x]){
		printf("%d ", u);
	}
	printf("\n");
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);	
		adj[u].pb(pii(v, (c=='B')));
		adj[v].pb(pii(u, (c=='B')));
	}
	for(int b=0;b<2;b++){
		for(int a=1;a<=n;a++){
			if(mrk[a]) continue;
			cor[a] = 0;
			cnt[0].pb(a);
			go(a, b);
			int i = 1;
			if(cnt[0].size() < cnt[1].size())
				i = 0;
			for(int v: cnt[i]){
				res[b].pb(v);
			}
			cnt[0].clear();
			cnt[1].clear();
		}
		for(int a=1;a<=n;a++){
			cor[a] = 0;
			mrk[a] = 0;
		}
	}
	if(fodeu[0] && fodeu[1])
		puts("-1");
	else if(fodeu[0])
		print(1);
	else if(fodeu[1])
		print(0);
	else{
		if(res[0].size() < res[1].size())
			print(0);
		else
			print(1);
	}
}
