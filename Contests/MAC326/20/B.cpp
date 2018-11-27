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

map<char, int> pos[MAXN];

map<int, int> mrk;

int main (){
	scanf("%d%d", &n, &m);
	int mn = INT_MAX;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			char c;
			scanf(" %c", &c);
			pos[a][c] = b;
		}	
		mn = min(mn, pos[a]['S'] - pos[a]['G']);
		mrk[pos[a]['S'] - pos[a]['G']] = 1;
	}
	if(mn < 0)
		puts("-1");
	else
		printf("%d\n", (int)mrk.size());
}

