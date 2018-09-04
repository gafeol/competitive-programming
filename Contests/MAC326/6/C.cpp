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

const int MAXN = 512;
const int MAXC = 10234;

int n, m, k;

struct app{
	int id, d, s;

	int mx() {
		return max(d, s);
	}

	int t() {
		return (d < s);
	}
} s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool cmp(app a, app b){
	return (a.s - a.d < b.s - b.d);
	if(a.t() != b.t())
		return a.t() < b.t();
	if(a.s != b.s)
		return a.s < b.s;
	return a.d > b.d;
}

int dp[MAXN][MAXC];

int go(int u, int c){
	int &r = dp[u][c];
	if(r != -1) 
		return r;
	if(u == n)
		return r = 0;
	r = max(r, go(u+1, c));
	if(c + s[u].mx() <= k)
		r = max(r, 1 + go(u+1, c + s[u].s));

	return r;
}

void re(int u, int c){
	int &r = dp[u][c];
	if(u == n)
		return ;
	if(r == go(u+1, c))
		re(u+1, c);
	else{
		printf("%d ", s[u].id+1);
		re(u+1, c + s[u].s);
	}
}

int main (){
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	for(int a=0;a<n;a++){
		int d, i;
		scanf("%d %d", &d, &i);
		s[a] = {a, d, i};
	}
	sort(s, s+n, cmp);
	int ans = go(0, 0);
	printf("%d\n", ans); 
	re(0, 0);
	puts("");
} 
