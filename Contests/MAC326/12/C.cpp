#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100045, BIT = (1<<6);

int n, m, k;
int s[MAXN];
int dp[MAXN][BIT];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int val[MAXN], cnt[MAXN];

int nc, visc;
int cy[MAXN], vis[MAXN], mn[MAXN], id[MAXN];
vector<int> adj[MAXN];
stack<int> q;

void reset(int nn=n){
	while(!q.empty()) q.pop();
	nc = visc = 0;
	for(int a=0;a<=n;a++){
		adj[a].clear();
		cy[a] = -1;
		vis[a] = 0;
	}
}


int tarjan(int u){
	q.push(u);
	vis[u] = 1;
	id[u] = visc++;
	mn[u] = id[u];
	for(int nxt: adj[u]){
		if(!vis[nxt])
			mn[u] = min(mn[u], tarjan(nxt));
		else if(cy[nxt] == cy[u])
			mn[u] = min(mn[u], id[nxt]);
	}
	if(mn[u] == id[u]){
		cy[u] = nc++;
		while(q.top() != u){
			cy[q.top()] = cy[u];
			q.pop();
		}
		q.pop();
	}
	return mn[u];
}

void scc(){
	// nodes 0..n-1
	for(int a=0;a<n;a++)
		if(!vis[a])
			tarjan(a);
}

int go(int u, int bm){
    int &r = dp[u][bm];
    if(r != -1) return r;
    r = 0;
    for(int nxt: adj[u]){
        int nbm = (1<<val[nxt]);
        if(cy[nxt] == cy[u]){
            if((bm&nbm) != 0) 
                continue;
            nbm = (nbm|bm);
        }
        r = max(r, 1 + go(nxt, nbm));
    }
    return r;
}

int main (){
	scanf("%d%d", &n, &m);
    reset();
    memset(dp, -1, sizeof(dp));
	for(int a=0;a<m;a++){
        int i, j;
        scanf("%d %d", &i, &j);
        i--;j--;
        adj[i].pb(j);
	}
    scc();
    for(int a=0;a<n;a++){
        val[a] = cnt[cy[a]]++;
    }
    int res = 0;
    for(int a=0;a<n;a++){ 
        res = max(res, go(a, (1<<val[a])));
    }
    printf("%d\n", res+1);
}

