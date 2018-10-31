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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int v[MAXN], p[MAXN], t[MAXN];
vector<int> gr[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &t[a]);
		v[t[a]] = a;
		p[t[a]] = 0;
	}
	int g = 0;
	for (int i=1;i<=n;i++) {
		if (p[v[i]] == 0) {
			int k = v[i];
			while (p[k] == 0 && k >= 0) {
				gr[g].pb(t[k]);
				p[k--] = 1;
			}
			g++;
		}
	}
	printf("%d\n", g);
	for (int i=0;i<g;i++) {
		printf("%d ", (int)gr[i].size());
		sort(gr[i].begin(), gr[i].end());
		for (auto a:gr[i]) {
			printf("%d ", a);
		}
		printf("\n");
	}
}

