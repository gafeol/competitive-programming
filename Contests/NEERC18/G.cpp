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
int s[MAXN];

vector<int> adj[MAXN];
vector<pii> lig[MAXN];

vector<pii> ar;


int st;

int ori[MAXN];
int mrk[MAXN];

void def(int id, int u, int v){
	if(ar[id].fst == u)
		ori[id] = 1;
	else
		ori[id] = 0;
}

int cnt = 0;

void go(int u, int t){
	cnt++;
	mrk[u] = 1;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt, t);
	}
	for(pii und: lig[u]){
		int nxt = und.fst;
		int id = und.snd;
		if(mrk[nxt]) continue;
		if(t == 0){
			def(id, u, nxt);
			go(nxt, t);
		}
		else{
			def(id, nxt, u);
		}
	}
}

int main (){
	scanf("%d%d %d", &n, &m, &st);
	for(int a=0;a<m;a++){
		int t, i, j;
		scanf("%d %d %d", &t, &i, &j);
		if(t == 1){
			adj[i].pb(j);
		}
		else{
			lig[i].pb(pii(j, ar.size()));
			lig[j].pb(pii(i, ar.size()));
			ar.pb(pii(i, j));
		}
	}
	go(st, 0);
	printf("%d\n", cnt);
	for(int a=0;a<(int)ar.size();a++){
		if(ori[a])
			printf("+");
		else
			printf("-");
	}
	puts("");
	memset(mrk, 0, sizeof(mrk));
	cnt = 0;
	go(st, 1);
	printf("%d\n", cnt);
	for(int a=0;a<(int)ar.size();a++){
		if(ori[a])
			printf("+");
		else
			printf("-");
	}
	puts("");
}

