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

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mx, mxu;
vector<int> adj[MAXN];

void dfs(int u, int p, int d){
    if(mx < d){
        mx = d;
        mxu = u;
    }
    for(int nxt: adj[u]){
        if(nxt == p) continue;
        dfs(nxt, u, d+1);
    }
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            adj[a].clear();
        for(int a=0;a<n-1;a++){
            int i, j;
            scanf("%d %d", &i, &j);
            adj[i].pb(j);
            adj[j].pb(i);
        }
        mx = -1;
        dfs(0, 0, 0);
        mx = -1;
        dfs(mxu, mxu, 0);
        printf("%d\n", (1+mx)/2);
    }
}

