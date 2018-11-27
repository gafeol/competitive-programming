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

const int MAXN = 312345;
const int MAXX = 5009;
const int INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

int d[MAXX][MAXX];

bool valid(int i, int j){
	return (i>=0 && j>= 0 && i<= 5000 && j<=5000);
}


void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int vi[] = {0, 0, 1, 1, 1, -1, -1, -1};
int vj[] = {1, -1, 1, 0, -1, -1, 0, 1};

int main (){
	scanf("%d%d", &n, &m);
	queue<pii> q;
	memset(d, INF, sizeof(d));
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		d[i][j] = 0;
		q.push({i, j});
	}
	while(!q.empty()){
		int i, j;
		tie(i, j) = q.front();
		q.pop();
		for(int dr=0;dr<8;dr++){
			int ii = i+vi[dr], jj = j + vj[dr];
			if(valid(ii, jj) && d[ii][jj] > d[i][j] + 1){
				d[ii][jj] = d[i][j] + 1;
				q.push({ii, jj});
			}
		}
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", d[i][j]);
	}
}

