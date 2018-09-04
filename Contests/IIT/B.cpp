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

int acu[66][66][66];
int befh[66][66][66];
int befm[66][66][66];
int befs[66][66][66];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int ispal(){
	string A = "";
	for(int a=0;a<3;a++){
		int val = s[a];
		A += '0' + s[a]/10;
		A += '0' + (s[a]%10);
	}
	for(int a=0;a<6;a++){
		if(A[a] != A[5-a]) return 0;
	}
	return 1;
}

int t[MAXN][4];

int main (){
	int ls, lm, lh = -1;
	for(int hh=0;hh<24;hh++){
		for(int mm=0;mm<60;mm++){
			for(int ss=0;ss<60;ss++){
				s[0] = hh;
				s[1] = mm;
				s[2] = ss;
				acu[hh][mm][ss] = ispal();
				if(lh != -1)
					acu[hh][mm][ss] += acu[lh][lm][ls];
				befh[hh][mm][ss] = lh;
				befm[hh][mm][ss] = lm;
				befs[hh][mm][ss] = ls;
				lh = hh;
				lm = mm;
				ls = ss;
			}
		}
	}
	scanf("%d", &n);
	while(n--){
		for(int a=0;a<2;a++){
			scanf("%d:%d:%d", &t[a][0], &t[a][1], &t[a][2]); 
		}
		int res = acu[t[1][0]][t[1][1]][t[1][2]];
		if(t[0][0] + t[0][1] + t[0][2] != 0){
			int bh = befh[t[0][0]][t[0][1]][t[0][2]];
			int bm = befm[t[0][0]][t[0][1]][t[0][2]];
			int bs = befs[t[0][0]][t[0][1]][t[0][2]];
			res -= acu[bh][bm][bs];
		}
		printf("%d\n", res);
	}
}

