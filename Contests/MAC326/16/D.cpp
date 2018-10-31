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
string s;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int vi[] = {0, 1, 0, -1};
int vj[] = {1, 0, -1, 0};

int mrk[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		cin >> ws >> s;
		int tam = s.size();
		int i = 0, j = 0;
		int mni = INT_MAX, mxi = INT_MIN;
		int mnj = INT_MAX, mxj = INT_MIN;
		int d = 0;
		for(int a=0;a<tam;a++){
			if(s[a] == 'R')
				d = (d+1)%4;
			else if(s[a] == 'B')
				d = (d+2)%4;
			else if(s[a] == 'L')
				d = (d+3)%4;
			i += vi[d];
			j += vj[d];
			mni = min(mni, i);
			mxi = max(mxi, i);
			mnj = min(mnj, j);
			mxj = max(mxj, j);
		}

		int nl = mxi - mni + 3;
		int nc = mxj - mnj + 2;
		i = abs(mni) + 1;
		j = 0;
		d = 0;
		mrk[i][j] = 1;
		for(int a=0;a<tam;a++){
			if(s[a] == 'R')
				d = (d+1)%4;
			else if(s[a] == 'B')
				d = (d+2)%4;
			else if(s[a] == 'L')
				d = (d+3)%4;
			i += vi[d];
			j += vj[d];
			mrk[i][j] = 1;
			mni = min(mni, i);
			mxi = max(mxi, i);
			mnj = min(mnj, j);
			mxj = max(mxj, j);
		}

		if(tt == 1){
			printf("%d\n", t);
		}

		printf("%d %d\n", nl, nc);
		for(int a=0;a<nl;a++){
			for(int b=0;b<nc;b++){
				if(mrk[a][b])
					printf(".");
				else
					printf("#");
			}
			puts("");
		}
	}
}

