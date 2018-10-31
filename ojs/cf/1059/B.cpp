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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char M[MAXN][MAXN];
int mrk[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(a + 2 >= n || b + 2 >= m) continue;
			int ok = 1;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(i == j && i == 1) continue;
					int aa = a+i, bb = b + j;
					if(M[aa][bb] == '.') ok = 0;
				}
			}
			if(ok){
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						if(i == j && i == 1) continue;
						int aa = a+i, bb = b + j;
						mrk[aa][bb] = 1;
					}
				}
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == '#' && !mrk[a][b]){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}

