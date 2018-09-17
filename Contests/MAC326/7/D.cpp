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
vector<int> adj[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int has[MAXN][30];

char x, y;

int A, mrk[MAXN], ans[MAXN];

void go(int u){
    mrk[u] = 1;
    for(int nxt:adj[u]){
        if(mrk[nxt]) continue;
        go(nxt);
    }
}

vector<int> res;

void solve(int u){
    ans[u] = 1;
    res.pb(u+1);
    for(int nxt: adj[u]){
        if(ans[nxt]  || !has[nxt][A]) continue;
        solve(nxt);
    }
}

int main (){
    freopen("kripke.in", "r", stdin);
    freopen("kripke.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		while(x--){
			char c;
			scanf(" %c", &c);
			has[a][c-'a'] = 1;
		}
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;j--;
		adj[j].pb(i);
	}
	scanf(" E(%cU(AG%c))", &x, &y);
    A = x-'a';

    for(int a=0;a<n;a++){
        if(has[a][y-'a']) continue;
        go(a);
    }
    for(int a=0;a<n;a++){
        if(!mrk[a] && !ans[a])
            solve(a);
    }
    printf("%d\n", (int)res.size());
    sort(res.begin(), res.end());
    for(int a: res)
        printf("%d\n", a);
}

