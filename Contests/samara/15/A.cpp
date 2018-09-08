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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int tempo, mrk[MAXN];

ll d[MAXN][MAXN];

int deg[MAXN];

void go(int u, int r){
	mrk[u] = tempo;

	ll mn = min(d[r][u], d[u][r]);
	d[r][u] -= mn;
	d[u][r] -= mn;


	for(int nxt=0;nxt<n;nxt++){
		if(d[u][nxt] == 0) continue;
		
		mn = min(d[r][u], d[u][nxt]);
		d[r][u] -= mn;
		d[u][nxt] -= mn;
		d[r][nxt] += mn;

		if(d[r][u] == 0 && r != u) return ;

		if(mrk[nxt] != tempo)
			go(nxt, r);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf("%lld", &d[a][b]);
		}
	}
	clock_t clk = clock();
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.5){
		for(int a=0;a<n;a++){
			tempo++;
			go(a, a);
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			printf("%lld ", d[a][b]);
		}
		puts("");
	}
}

