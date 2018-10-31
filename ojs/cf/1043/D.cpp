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

const int MAXN = 112345;

int n, m, k;
int s[13][MAXN];
int pos[13][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool has(int a, int b){
	for(int i=0;i<m;i++)
		if(pos[i][a] +1 != pos[i][b])
			return false;
	return true;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		for(int b=0;b<n;b++){
			scanf("%d", &s[a][b]);
			pos[a][s[a][b]] = b;
		}
	}
	int mx[MAXN];
	memset(mx, 0, sizeof(mx));
	ll res = 0;
	for(int i=n-1;i>=0;i--){
		mx[i] = 1;
		if(has(s[0][i], s[0][i+1])){
			mx[i] = mx[i+1] + 1;	
		}
		res += (ll)mx[i];
	}
	printf("%lld\n", res);
}

