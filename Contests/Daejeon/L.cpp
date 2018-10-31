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

const int MAXN = 100;
const int T = 50*50*53;
const ll oo = numeric_limits<ll>::max()/4;

int n, m, k;
int s[MAXN];
int nn[5];
ll cost[T][MAXN][5];
ll h[MAXN];
int e[5];

struct edge {
    int a, b; ll g;
};

vector<edge> adj[5];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
    int p;
	scanf("%d", &p);
	for(int i=0;i<p;i++){
	    int n, m; scanf("%d %d", &nn[i], &m);
        n = nn[i];
        for (int j=0;j<n;j++) {
            for (int ss = 0; ss < T; ss++) {
                cost[ss][j][i] = oo;
            }
            scanf("%lld", &h[j]);
            adj[i].pb({j, j, h[j]});
        }
        for (int j=0;j<m;j++) {
            int a, b; ll c;
            scanf("%d %d %lld", &a, &b, &c);
            a--; b--;
            adj[i].pb({a, b, c});
        }
        scanf("%d", &e[i]);
        e[i]--;
        cost[0][0][i] = 0;
    }
    ll resp = 3ll * oo;
    for (int step = 0; step < T; step++) {
        ll c = 0ll;
        for (int i = 0; i < p; i++) {
            c += cost[step][e[i]][i];
            //printf("cost[%d][%d][%d] = %lld\n", step, 2, i, cost[step][2][i]);
            for (int j = 0; step < T-1 && j < adj[i].size(); j++) {
                edge ee = adj[i][j];
                cost[step+1][ee.b][i] = min(cost[step+1][ee.b][i], cost[step][ee.a][i] + ee.g);
            }
        }
        resp = min(resp, c);
        //printf("%lld\n", resp);
    }
    printf("%lld\n", resp);
}

