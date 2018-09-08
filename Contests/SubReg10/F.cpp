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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int s[MAXN][MAXN];

vector<int> p;

set<int> gan;

int pont[MAXN];
int ind[MAXN];

bool cmp(int i, int j){
	return ((pont[i] == pont[j] && i < j) || pont[i] > pont[j]);
}

int main (){
	while(scanf("%d %d", &n, &m) != EOF && n+m > 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				int x;
				scanf("%d", &x);
				s[a][x-1] = b;
			}
		}
		int q;
		scanf("%d", &q);
		for(int a=0;a<q;a++){
			int x;
			scanf("%d", &x);
			p.clear();
			while(x--){
				int val;
				scanf("%d", &val);
				p.pb(val);
			}
			memset(pont, 0, sizeof(pont));
			for(int i=0;i<n;i++){
				for(int j=0;j<p.size();j++){
					pont[s[i][j]] += p[j];
				}
			}
			int mx = INT_MIN, imx;
			for(int i=0;i<m;i++)
				ind[i] = i;
			sort(ind, ind+m, cmp);
			int u =0;
			int fst = 1;
			do{
				if(!fst) printf(" ");
				fst = 0;
				printf("%d", ind[u]+1);
				u++;
			} while(u < m && pont[ind[u-1]] == pont[ind[u]]);
			puts("");
		}
	}
}

