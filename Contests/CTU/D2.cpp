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

const int MAXN = 412345;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> x;

vector<int> X[MAXN], Y[MAXN];
unordered_map<int, vector<int> > D;

int px[MAXN], py[MAXN], pd[MAXN];


void limpa(){
	D.clear();
	for(int a=0;a<MAXN;a++){
		X[a].clear();
		Y[a].clear();
	}
	x.clear();
}

pii s[MAXN];

int vd(pii x){
	return ::x[x.snd] - ::x[x.fst];
}

int main (){
	while(scanf("%d", &n) != EOF){ 
		limpa();
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			x.pb(i);
			x.pb(j);
			s[a] = pii(i, j);
		}
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		for(int a=0;a<n;a++){
			s[a].fst = lower_bound(x.begin(), x.end(), s[a].fst) - x.begin();
			s[a].snd = lower_bound(x.begin(), x.end(), s[a].snd) - x.begin();
		}

		for(int a=0;a<n;a++){
			X[s[a].snd].pb(s[a].fst);
			Y[s[a].fst].pb(s[a].snd);
			D[vd(s[a])].pb(s[a].fst);
		}
		for(int a=0;a<MAXN;a++){
			sort(X[a].begin(), X[a].end());
			sort(Y[a].begin(), Y[a].end());
			sort(D[a].begin(), D[a].end()); }
		int res = 0;
		for(int a=0;a<n;a++){
			int x = s[a].fst, y = s[a].snd;
			int d = vd(s[a]);
			vector<int> &diag = D[d];
			px[a] = upper_bound(X[y].begin(), X[y].end(), x) - X[y].begin();
			py[a] = upper_bound(Y[x].begin(), Y[x].end(), y) - Y[x].begin();
			pd[a] = upper_bound(diag.begin(), diag.end(), x) - diag.begin();

			while(px[a] < X[y].size() && py[a] < Y[x].size() && pd[a] < diag.size()){
				int dx = ::x[X[y][px[a]]] - ::x[x];
				int dy = ::x[Y[x][py[a]]] - ::x[y];
				int dd = ::x[diag[pd[a]]] - ::x[x];
				int mx = max(max(dx, dy), dd);

				//printf("a %d (%d, %d) dx %d dy %d dd %d\n", a, s[a].fst, s[a].snd, dx, dy, dd);
				if(dx < mx)
					px[a]++; 
				else if(dy < mx)
					py[a]++;
				else if(dd < mx)
					pd[a]++;
				else{
					res = max(res, mx);
					px[a]++;
				}
			}
		}
		printf("%d\n", res);
	}
}

