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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int sz[5];
int s[5][MAXN];
long long v[MAXN];

int main (){
	int t; scanf("%d", &t);
	while (t--) {
		for (int i=0;i<3;i++) {
			scanf("%d", &sz[i]);
			for (int j=0;j<sz[i];j++) {
				scanf("%d", &s[i][j]);
			}
		}
		for (int j=0;j<sz[1];j++) {
			int k = lower_bound(s[2], s[2] + sz[2], s[1][j]) - s[2];
			k = min(max(k, j), sz[2]);
			v[j] = (long long)(sz[2] - k);
		}
		v[sz[1]] = 0;
		for (int i=sz[1]-1;i>=0;i--) {
			v[i] += v[i+1];
		}
		long long resp = 0;
		for (int i=0;i<sz[0];i++) {
			int j = lower_bound(s[1], s[1] + sz[1], s[0][i]) - s[1];
			j = min(max(i, j), sz[1]);
			resp += v[j];
		}
		printf("%lld\n", resp);
	}
}

