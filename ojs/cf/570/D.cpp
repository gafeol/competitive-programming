#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512345;

int n, m, k;

int prof[MAXN];

vector <int> adj[MAXN];

vector <int> vt[MAXN];

vector <int> ind[MAXN];

vector <int> freq[MAXN];

int v[MAXN], deg[MAXN], cnt, mxh;
pii l[MAXN];

void go(int u, int h){
	prof[u] = h;
	mxh = max(mxh, h);
	l[u].fst = cnt;
	deg[u] = cnt++;
	vt[h].pb(u);
	ind[h].pb(deg[u]);
	for(int nxt: adj[u]){
		go(nxt, h+1);
	}
	l[u].snd = cnt++;
//	printf("%d %d: %d %d\n", u, deg[u], l[u].fst, l[u].snd);
}

int bb(int h, int v){
	int i = 0, j = ind[h].size()-1;
	while(i < j){
		//printf("%d %d- %d %d ind[%d][%d] %d\n", h, v, i, j, h, m, ind[h][m]);
		//printf("i %d j %d\n", i, j);
		int m = (i+j)/2;
		if(ind[h][m] >= v)
			j = m;
		else
			i = m + 1; 
	}
	return i;
}

int main (){
	cnt = 1;
	scanf("%d%d", &n, &m);
	int p;
	for(int a=2;a<=n;a++){	
		scanf("%d", &p);
		adj[p].pb(a);
	}
	char c;
	for(int a=1;a<=n;a++){
		scanf(" %c", &c);
		v[a] = (int)(c-'a');
	}
	mxh = 0;
	go(1, 0);
	for(int a=0;a<=mxh;a++){
		ind[a].pb(INT_MAX);
	}
	for(int a=0;a<=mxh;a++){
		for(int b=0;b<vt[a].size();b++){
			freq[a].pb(0);
			if(b > 0)
				freq[a][b] = freq[a][b-1];
			else
				freq[a][b] = 0;
			freq[a][b] ^= (1<<v[vt[a][b]]);
		//	printf("freq[%d][%d] %d (v[%d] %d)\n", a, b, freq[a][b], vt[a][b], (1<<v[vt[a][b]]));
		}
	}
	for(int a=0;a<m;a++){
		int u, h;
		scanf("%d%d", &u, &h);
		h--;
		if(h <= prof[u]){
			puts("Yes");
			continue;
		}
		int i = bb(h, l[u].fst);
		int j = bb(h, l[u].snd)-1;
//		printf("i %d j %d\n", i, j);
		if(i > j){
			puts("Yes");
			continue;
		}
		int ans = freq[h][j];
		if(i-1 >= 0)
			ans ^= freq[h][i-1];
		if(__builtin_popcount(ans) > 1)
			puts("No");
		else
			puts("Yes");
	}
}
