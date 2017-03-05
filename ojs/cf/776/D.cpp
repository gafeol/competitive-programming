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
int s[MAXN], cnt[MAXN], dr[MAXN][2], mrk[MAXN], mrk2[MAXN];

vector<pii> adj[MAXN];
int fodeu;


void go(int i, int c){
	mrk2[i] = c;
	if(fodeu) return;
	for(pii nxt: adj[i]){
		if(fodeu) return;
		int v = nxt.fst;
		if(mrk2[v] != 0){
			if(nxt.snd == ((c-1)^(mrk2[v]-1))){
				fodeu = 1;
				return;
			}
			continue;
		}
		go(v, !((c-1)^nxt.snd) + 1);
	}
}

void limpa(int i){
	mrk2[i] = 0;
	for(pii nxt: adj[i]){
		int v = nxt.fst;
		if(mrk2[v] != 0)
			limpa(v);
	}
}

void marca(int i, int c){
	mrk[i] = c;
	if(fodeu) return;
	for(pii nxt: adj[i]){
		if(fodeu) return;
		int v = nxt.fst;
		if(mrk[v] != 0){
			if(nxt.snd == ((c-1)^(mrk[v]-1))){
				fodeu = 1;
				return;
			}
			continue;
		}
		go(v, !((c-1)^nxt.snd) + 1);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=0;a<m;a++){
		int t;
		scanf("%d", &t);
		while(t--){
			int x;
			scanf("%d", &x);
			x--;
			dr[x][cnt[x]++] = a;
		}
	}
	for(int a=0;a<n;a++){
		adj[dr[a][0]].pb(pii(dr[a][1], s[a]));
		adj[dr[a][1]].pb(pii(dr[a][0], s[a]));
	}
	for(int a=0;a<m;a++){
		if(mrk[a] != 0) continue;
		fodeu = 0;
		go(a, 2);
		if(!fodeu){
			marca(a, 2);
			continue;
		}
		limpa(a);
		fodeu = 0;
		go(a, 1);
		if(!fodeu){
			marca(a, 1);
			continue;
		}
		puts("NO");
		return 0;
	}
	puts("YES");
}
