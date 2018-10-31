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

const int MAXN = 2123;

int n, m, k;
int x, y;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int f[2][MAXN], t[MAXN];

pii ar[MAXN];

vector<pii> adj[MAXN];
vector<int> res;

int bef[MAXN];

int at;

void move(int v){
    if(res.back() == y) return ;
    if(at != v){
        res.pb(v);
        at = v;
    }
}

void print(int u){
    vector<int> p;
    while(bef[u] != u){
        p.pb(u);
        u = bef[u];
    }
    p.pb(u);

    at = x;

    for(int i=p.size()-1;i>=0;i--)
        move(p[i]);
    for(int i=0;i<p.size();i++)
        move(p[i]);
}

void dfs(int u, int p){
    bef[u] = p;
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        int c = ar.snd;
        if(nxt == p) continue;
        dfs(nxt, u);
    }
}

void go(int u, int p){
    if(s[u] != -1){
        f[0][s[u]] = u;
    }
    for(pii ar: adj[u]){
        int nxt = ar.fst;
		int c = ar.snd;
		if(nxt == p) continue;
		if(c == -1)
			go(nxt, u);
		else{
			f[1][c] = nxt;
			if(t[c])
				go(nxt, u);
		}
	}
}

int main (){
	while(scanf("%d%d%d%d", &n, &k, &x, &y) != EOF && n+m+x+y > 0){
		memset(s, -1, sizeof(s));
		res.clear();
		res.pb(x);
		for(int a=0;a<n;a++){
			adj[a].clear();
		}
		for(int a=0;a<=k;a++){
			f[0][a] = -1;
			f[1][a] = -1;
			t[a] = 0;
		}
		for(int a=0;a<k;a++){
			int v;
			scanf("%d", &v); 
			s[v] = a;
		}
		s[y] = k;
		for(int a=0;a<n-1;a++){
			int i, j, c;
			scanf("%d%d%d", &i, &j, &c);
			adj[i].pb(pii(j, c));
			adj[j].pb(pii(i, c));
		}
		dfs(x, x);
		while(1){
			go(x, x);
			if(f[0][k] != -1){
				print(f[0][k]);
				break;
			}
			int foi = 0;
			for(int a=0;a<k;a++){
				if(f[0][a] != -1 && f[1][a] != -1 && !t[a]){
					foi = 1;
					print(f[0][a]);
					print(f[1][a]);
					t[a] = 1;
				}
			}
			if(!foi)
				break;
		}
		if(res.back() == y){
			printf("%d: ", (int)res.size()-1);
			for(int i=0;i < res.size();i++)
				printf("%d%c", res[i], " \n"[i == res.size()-1]);
		}
		else
			puts("Impossible");
	}
}

