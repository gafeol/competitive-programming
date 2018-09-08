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

char M[123][123];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int i, j, d;

int vi[] = {-1, 0, 1, 0};
int vj[] = {0, 1, 0, -1};

char c[MAXN];

int l(char c){
	int d;
	if(c == 'N')
		d = 0;	
	else if(c == 'L')
		d = 1;
	else if(c == 'S')
		d = 2;
	else if(c == 'O')
		d = 3;
	return d;
}

bool valid(int i, int j){
	return (i>=0 && j>=0 && i < n && j < m && M[i][j] != '#');
}

int main (){
	while(scanf("%d%d%d", &n, &m, &k) != EOF && n+m+k != 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf(" %c", &M[a][b]);

				if(M[a][b] != '*' && M[a][b] != '#' && M[a][b] != '.'){
					d = l(M[a][b]);
					i = a; j = b;
					M[a][b] = '.';
				}
			}
		}
		scanf(" %s", c);
		int res = 0;
		for(int a=0;a<k;a++){
			if(M[i][j] == '*'){
				M[i][j] = '.';
				res++;
			}
			if(c[a] == 'F'){
				int ii = i + vi[d], jj = j + vj[d];
				if(valid(ii, jj)){
					i = ii;
					j = jj;
				}
			}
			else if(c[a] == 'D')
				d = (d+1)%4;
			else
				d = (d+3)%4;

			if(M[i][j] == '*'){
				M[i][j] = '.';
				res++;
			}
		}
		printf("%d\n", res);
	}
}

