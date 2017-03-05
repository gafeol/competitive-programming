
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

vector<int> adj[MAXN];
int tempo;

inline int no(int x){
	return x+m;
}


void go(int u){
	mrk[u] = tempo;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);
	}
}

int main (){
	tempo = 1;
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
		if(s[a]){
			adj[dr[a][0]].pb(dr[a][1]);
			adj[dr[a][1]].pb(dr[a][0]);
			adj[no(dr[a][0])].pb(no(dr[a][1]));
			adj[no(dr[a][1])].pb(no(dr[a][0]));
		}
		else{
			adj[dr[a][0]].pb(no(dr[a][1]));
			adj[dr[a][1]].pb(no(dr[a][0]));
			adj[no(dr[a][0])].pb(dr[a][1]);
			adj[no(dr[a][1])].pb(dr[a][0]);
		}
	}
	for(int a=0;a<no(m-1);a++){
		if(mrk[a]) continue;
		tempo++;
		go(a);
	}
	for(int a=0;a<m;a++){
		if(mrk[a] == mrk[no(a)]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
