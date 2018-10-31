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


bool mrk[MAXN];
vector<pii> adj[MAXN];


bool nfoi[140000000];

int bm[MAXN];

int has[34];
int cnt;

void add(int x){
    ///printf("add %d\n", x);
    int nb = __builtin_clz(x);
    while(nb < 31 && has[nb]){
        if(nfoi[x]) return ;
        nfoi[x] = 1;
        //printf("x %d has[%d] %d\n", x, nb, has[nb]);
        x ^= has[nb];
        nb = __builtin_clz(x);
        //printf("new x %d nb %d\n", x, nb);
    }
    //printf("upd x %d, nb %d\n", x, nb);
    if(x == 0) return ;
    has[nb] = x;
    nfoi[x] = 1;
    cnt++;
}

void go(int u, int d){
    //printf("go %d %d\n", u, d);
    mrk[u] = true;
    bm[u] = d;
    for(pii ar: adj[u]){
        int nxt = ar.fst;
        int dis = ar.snd;
        if(mrk[nxt]){
            add(d^bm[nxt]^dis);
            continue;
        }
        go(nxt, d^dis);
    }
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i, j, c;
        scanf("%d%d%d", &i, &j, &c);
        adj[i].pb(pii(j, c));
        adj[j].pb(pii(i, c));
	}
    go(1, 0);
    int res = bm[n];
    for(int a=0;a<32;a++){
        if((res^has[a]) < res)
            res ^= has[a];
    }
    printf("%d\n", res);
}

