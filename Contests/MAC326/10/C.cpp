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

const int MAXN = 102;

const int INF = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];

vector<pii> adj[30];
vector<int> cus[30];

int dp[28][MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int go(int u, int i, int j){
    debug(u, i, j);
    int &r = dp[u][i][j];
    if(r != -1) return r;
    r = INF;
    if(i == j)
        return r = INF*(s[i] != u);
    for(int a=i;a<j;a++){
        for(int b=0;b<adj[u].size();b++){
            pii p = adj[u][b];
            int cus = ::cus[u][b];
            r = min(r, go(p.fst, i, a) + go(p.snd, a+1, j) + cus);
        }
    }
    return r;
} 
int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &m);
        for(int a=0;a<26;a++){
            adj[a].clear();
            cus[a].clear();
        }
        for(int a=0;a<n;a++){
            char c, l, r;
            int cus;
            scanf(" %c %c %c %d", &c, &l, &r, &cus);
            c -= 'A';
            l -= 'A';
            r -= 'A';
            adj[c].pb(pii(l, r));
            ::cus[c].pb(cus);
        }
        printf("CASE #%d\n", tt);
        for(int a=0;a<m;a++){
            int tam;
            scanf("%d %s", &tam, s);  
            for(int i=0;i<tam;i++){
                s[i] = toupper(s[i]) - 'A';
            }
            memset(dp, -1, sizeof(dp));
            int res = tam + go(0, 0, tam-1);
            if(res >= INF)
                puts("IMPOSSIBLE");
            else
                printf("POSSIBLE WITH %d DIAMONDS\n", res);
        }
    }
}
