#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
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

#define lbi fst.snd
#define lbj fst.fst
#define rui snd.snd
#define ruj snd.fst

const int MAXN = 512345;

int n, k;
ppp s[MAXN];
unordered_map<int,vector<int> > q[2];
vector<int> adj[MAXN];
int c[MAXN];
bool cmp(int a, int b){
	return (s[a].lbj < s[b].lbj || (s[a].lbj == s[b].lbj && s[a].ruj > s[b].ruj));
}

bool cmp2(int a, int b){
	return (s[a].lbi < s[b].lbi || (s[a].lbi == s[b].lbi && s[a].rui > s[b].rui));
}

int res = 0;
clock_t clk;

void go(int u){
	if(((double)clk - clock())/CLOCKS_PER_SEC > 1.8) return;
	if(u != 0)
		debug("u %d c[%d] %d\n", u, u-1, c[u-1]);
	if(res) return;
	if(u == n){
		res = 1;
		return;
	}
	int bm = 0;
	for(int nxt: adj[u]){
		if(c[nxt] == -1) continue;
		bm |= (1<<c[nxt]); 
	}
	debug("bm %d\n", bm);
	for(int i=0;i<4;i++){
		if((bm&(1<<i)) == 0){
			c[u] = i;
			go(u+1); 
		}
		if(res) return;
	}
}

int main (){
	clk = clock();
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d%d%d%d", &s[a].lbj, &s[a].lbi, &s[a].ruj, &s[a].rui);
		q[0][s[a].lbi].pb(a);
		q[0][s[a].rui].pb(a);
		q[1][s[a].lbj].pb(a);
		q[1][s[a].ruj].pb(a);
	}
	for(auto& m: q[0]){
		vector<int> x = m.snd;
		sort(x.begin(), x.end(), cmp);
		int i = 0, j = 1;
		while(j < x.size()){
			while(i < j && s[x[i]].ruj <= s[x[j]].lbj)
				i++;
			for(int a=i;a<j;a++){
				debug("liga V %d e %d\n", x[i]+1, x[j]+1);
				adj[x[i]].pb(x[j]);
				adj[x[j]].pb(x[i]);
			}
			j++;
		}
	}
	for(auto& m: q[1]){
		vector<int> x = m.snd;
		sort(x.begin(), x.end(), cmp2);
		int i = 0, j = 1;
		while(j < x.size()){
			while(i < j && s[x[i]].rui <= s[x[j]].lbi)
				i++;
			for(int a=i;a<j;a++){
				debug("liga H %d e %d\n", x[i]+1, x[j]+1);
				adj[x[i]].pb(x[j]);
				adj[x[j]].pb(x[i]);
			}
			j++;
		}
	}
	memset(c,-1, sizeof(c));
	go(0);
	if(res){
		puts("YES");
		for(int a=0;a<n;a++){
			printf("%d\n", c[a]+1);
		}
	}
	else
		puts("NO");
}
