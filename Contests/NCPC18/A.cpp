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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

tuple<int, int, int> s[MAXN];
int dp[(int)1e8 + 10];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		int l, w, h; 
		scanf("%d%d%d", &l, &w, &h);
		s[a] = {-w, l, h};
	}
	sort(s, s+n);
	int res = 0;
	for(int a=0;a<n;a++){
		int l, w, h; 
		tie(w, l, h) = s[a];
		w *= -1;
		if(dp[w] + l > k)
			res++;
		for(int i=0;i<w;i++){
			dp[i] = max(dp[i], dp[min((int)1e8, i+w)] + h);
		}
	}
	printf("%d\n", res);
}

