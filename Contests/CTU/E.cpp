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
const int MAXM = 105;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int board[MAXM][MAXM];
void try_paint(int x, int y, int c, int m) {
	x++; y++;
	if (x > m || x < 1 || y > m || y < 1) return;
	board[x][y] = c;
}

void paint(int s, int x, int y, int m) {
	try_paint(x-1, y, '_', m);
	try_paint(x, y, (s == 0) ? 'o' : '|', m);
	try_paint(x+1, y, '_', m);
	for (int yy = y+1; yy <= y + s; yy++) {
		try_paint(x-1, yy, '/', m);
		try_paint(x, yy, (s == 0) ? 'o' : '|', m);
		try_paint(x+1, yy, '\\', m);
	}
	if (s > 0) try_paint(x, y+s+1, '^', m);
}

void clear_board(int m) {
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=m;j++) {
			board[i][j] = '.';
		}
	}
}

void print(int m) {
	for (int i=m+1;i>=0;i--) {
		for (int j=0;j<=m+1;j++) {
			if (i == 0 || j == 0 || i == m+1 || j == m+1) printf("*");
			else printf("%c", board[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

int main (){
	while (scanf("%d %d", &m, &n) != EOF) {
		clear_board(m);
		while (n--) {
			int s, x, y; scanf("%d %d %d", &s, &x, &y);
			paint(s, x, y, m);
		}
		print(m);
	}
}

