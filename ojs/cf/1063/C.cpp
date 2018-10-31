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
char s[MAXN];

int ST = 1000;

int fst, inv;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mn[3], mx[3];

int cnt;

void fim(){
	if(cnt < n) return ;
	printf("%d %d %d %d\n", 11, mx[0], 9, mn[1]);
	exit(0);
}

int chuta(int j){
	if(cnt == n) return -1;
	cnt++;
	printf("%d %d\n", 10, j);
	fflush(stdout);
	scanf(" %s", s);

	int ans = (s[0] == 'w');

	if(fst){
		fst = 0;
		inv = ans; 
	}

	ans = (ans^inv);

	mn[ans] = min(mn[ans], j);
	mx[ans] = max(mx[ans], j);
	fim();
	return ans;
}


int main (){
	fst = 1;
	scanf("%d", &n);
	mx[0] = mx[1] = 0;
	mn[0] = mn[1] = 1e9;
	chuta(0);

	while(1){
		int m = (mx[0] + mn[1]) /2;
		chuta(m);
	}
	
}

