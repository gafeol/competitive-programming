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
char s[MAXN], v[MAXN];

int mrk[500][500];

int vis[500];

vector<int> adj[500];

vector<int> l, r;

void go(int u){
	vis[u] = 1;
	for(int a=0;a<adj[u].size();a++){
		int nxt = adj[u][a];
		if(vis[nxt]) continue;
		l.pb(u);
		r.pb(nxt);
		go(nxt);
	}
}

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	scanf(" %s", v);
	for(int a=0;a<n;a++){
		if(s[a] != v[a] && !mrk[s[a]][v[a]]){
			mrk[s[a]][v[a]];
			mrk[v[a]][s[a]];
			adj[s[a]].pb(v[a]);
			adj[v[a]].pb(s[a]);
		}
	}
	for(int a='a';a<='z';a++){
		if(!vis[a])
			go(a);
	}
	printf("%d\n", (int)l.size());
	for(int a=0;a<l.size();a++){
		printf("%c %c\n", l[a], r[a]);
	}
}

