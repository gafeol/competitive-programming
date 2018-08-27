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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char M[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	int mn[2];
	mn[0] = INT_MAX;
	mn[1] = INT_MAX;
	int mx[2];
	mx[0] = INT_MIN;
	mx[1] = INT_MIN;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'B'){
				mn[0] = min(mn[0], a);
				mx[0] = max(mx[0], a);
				mn[1] = min(mn[1], b);
				mx[1] = max(mx[1], b);
			}
		}
	}
	printf("%d %d\n", (mn[0] + mx[0])/2+1,1+ (mn[1] + mx[1])/2);
}

