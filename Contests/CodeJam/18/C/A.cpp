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
int charat[30][400];

string w[MAXN];

map<int, map<char, int> > adj;
int deg;

vector<char> ans;

void add(int i){
	int u = 0;
	for(char c: w[i]){
		if(adj[u].find(c) == adj[u].end()){
			adj[u][c] = deg++;
		}	
		assert(adj[u][c] < deg);
		u = adj[u][c];
	}
}

int qry(int u, int p){
	int mrk[400];
	for(int a='A';a<='Z';a++)
		mrk[a] = 0;
	for(auto it: adj[u])
		mrk[it.fst] = 1;
	for(int c='A';c<='Z';c++){
		if(!mrk[c] && charat[p][c]){
			int a = charat[p][c]-1;
			for(int b=p;b<m;b++)
				ans.pb(w[a][b]);
			return 1;
		}

	}
	for(auto it: adj[u]){
		ans.pb(it.fst);
		if(qry(it.snd, p+1))
			return 1;
		ans.pop_back();
	}
	return 0;
}

int main (){
	for_tests(t, tt){
		deg = 1;
		ans.clear();
		adj.clear();
		debug("sz all %d\n", (int)adj.size());
		debug("sz %d\n", (int)adj[0].size());
		scanf("%d%d", &n, &m);
		for(int a=0;a<=m;a++)
			for(int b='A';b<='Z';b++)
				charat[a][b] = 0;

		for(int a=0;a<n;a++){
			char c;
			cin >> w[a];
			for(int b=0;b<m;b++){
				charat[b][w[a][b]] = 1+a;
			}
		}
		for(int a=n-1;a>=0;a--)
			add(a);

		printf("Case #%d: ", tt);
		if(qry(0, 0)){
			for(char c: ans)
				printf("%c", c);
			puts("");
		}
		else{
			puts("-");
		}
	}
}

