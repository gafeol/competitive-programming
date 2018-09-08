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

int has[MAXN];
int res;
int p[MAXN], sz[MAXN];

int raiz(int u){
	if(p[u] == u) return u;
	return raiz(p[u]);
}

void join(int i, int j){
	debug("join", i, j);
	i = raiz(i);
	j = raiz(j);
	if(i == j) return;
	if(sz[i] < sz[j]) swap(i, j);
	p[j] = i;
	sz[i] += sz[j];
	res++;
	debug("foi");
}

int main (){
	scanf("%d%d", &m, &n);
	memset(has, -1, sizeof(has));
	for(int a=0;a<m;a++){
		p[a] = a;
		sz[a] = 1;
	}
	for(int a=0;a<m;a++){
		int sz;
		scanf("%d", &sz);
		while(sz--){
			int x;
			scanf("%d", &x);
			x--;
			if(has[x] != -1){
				join(has[x], a);
			}
			has[x] = a;
		}
	}
	printf("%d\n", res);
}

