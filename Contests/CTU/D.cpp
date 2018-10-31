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

unordered_map<int, vector<int> > D[4];

unordered_map<int, unordered_map<int, int> > M;

void limpa(){
	M.clear();
	D[0].clear();
	D[3].clear();
	D[2].clear();
	D[1].clear();
}

pii s[MAXN];

int go(int t, int a, int b){
	int x = s[a].fst;
	int y = s[a].snd;
	int xx = s[b].fst;
	int yy = s[b].snd;
	int l = max(abs(yy - y), abs(xx - x));

	x = min(x, xx);
	y = min(y, yy);

	return (M[x][y] && M[x+l][y+l] && M[x][y+l] && M[x+l][y])*(l);
}

int main (){
	while(scanf("%d", &n) != EOF){ 
		limpa();
		ll res[5];
		memset(res, 0, sizeof(res));

		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			s[a] = pii(i, j);
			M[i][j] = 1;
			res[0] += D[0][i].size();
			D[0][i].pb(a);
			res[1] += D[1][j].size();
			D[1][j].pb(a);
			res[2] += D[2][i+j].size();
			D[2][i+j].pb(a);
			res[3] += D[3][i-j].size();
			D[3][i-j].pb(a);
		}

		int mn = *min_element(res, res+4);
		int ans = 0;
		for(int a=0;a<4;a++){
			if(res[a] == mn){
				for(auto it: D[a]){
					for(int i=0;i<it.snd.size();i++){
						for(int j=i+1;j<it.snd.size();j++){
							ans= max(go(a, it.snd[i], it.snd[j]), ans);
						}
					}
				}
				break;
			}
		}

		printf("%d\n",ans);
	}
}

