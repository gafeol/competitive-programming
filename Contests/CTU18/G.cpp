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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

const double EPS = 6e-7;

vector<pii> pos[10][10];

double go1(int i, int j, int ii, int jj, double p){
	if(i == ii & j == jj)  return -p;
	if(p < EPS) return 0;
	int ni, nj, nii, njj;
	double ans = 0, p1 = (((double)1.0)/pos[i][j].size()), p2 = (((double)1.0)/pos[ii][jj].size());
	for(pii nv: pos[i][j]){
		ni = nv.fst;
		nj = nv.snd;

		if(ni == ii && nj == jj)
			ans += p*p1;
		else{
			for(pii nvv: pos[ii][jj]){
				nii = nvv.fst;
				njj = nvv.snd;
				ans += go1(ni, nj, nii, njj, p*p1*p2);
			}
		}
	}
	return ans;
}
double go(int i, int j, int ii, int jj, double p){
	if(i == ii & j == jj)  return -p; 
	if(p < EPS) return 0;
	int ni, nj, nii, njj;
	double ans = 0, p1 = (1.0/pos[i][j].size()), p2 = (1.0/pos[ii][jj].size());
	for(pii nv: pos[i][j]){
		ni = nv.fst;
		nj = nv.snd;

		if(ni != ii || nj != jj){
			for(pii nvv: pos[ii][jj]){
				nii = nvv.fst;
				njj = nvv.snd;
				ans += go(ni, nj, nii, njj, p*p1*p2);
			}
		}
	}
	return ans;
}

int main (){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			for(int ii=1;ii<=8;ii++){
				for(int jj=1;jj<=8;jj++){
					int di = abs(ii - i), dj = abs(jj - j);
					if(max(di, dj) == 2 && min(di, dj) == 1){
						pos[i][j].pb({ii, jj});
					}
				}
			}
		}
	}
	int i, j, ii, jj;
	scanf("%d%d%d%d", &i, &j, &ii, &jj);
	double w1 = go1(i, j, ii, jj, 1.);
	double dif = w1;
	if(dif > 1e-6)
		puts("white");
	else if(dif > -1e-6)
		puts("draw");
	else
		puts("black");
}

