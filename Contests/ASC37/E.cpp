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

const int MAXN = 252345;

int n, m, k;
int kmp[MAXN];

void build(string p) {
	int n = p.size(), k = -1;
	kmp[0] = k;
	for (int i = 1; i < n + 1; i++) {
		while (k >= 0 && p[k] != p[i-1]) k = kmp[k];
		kmp[i] = ++k;
	}
}

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int resp[MAXN];
int bg[MAXN];

int main (){
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	string s;
	cin >> s;
	build(s);
	for (int i=1;i<=s.size();i++) bg[i] = i;
	for (int i=1;i<=s.size();i++) {
		if (bg[resp[kmp[i]]] + kmp[i] >= i) resp[i] = resp[kmp[i]];
		else resp[i] = i;
		bg[resp[i]] = i;
		printf("%d ", resp[i]);
	}
	printf("\n");
}

