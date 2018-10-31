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

int res;
int n, m, k;
int s[MAXN];

int mrk[MAXN][MAXN];
char M[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '*');
}

queue<tuple<int, int, int, int> > q;

void add(int i, int j, int x, int y){
	//printf("add %d %d %d %d\n", i, j, x, y);
	if(x < 0 || y < 0 || !valid(i, j)) return ;
	if(mrk[i][j]) return ;
	for(int a=-1;;a--){
		int ii = i + a;
		if(valid(ii, j)){
			res++;
			mrk[ii][j] = 1;
			q.push({ii, j, x, y});
		}
		else 
			break;
	}
	for(int a=0;;a++){
		int ii = i + a;
		if(valid(ii, j)){
			res++;
			mrk[ii][j] = 1;
			q.push({ii, j, x, y});
		}
		else 
			break;
	}
}

int main (){
	scanf("%d%d", &n, &m);
	int i, j;
	scanf("%d%d", &i, &j);
	i--; j--;
	int x, y;
	scanf("%d%d", &x, &y);
	swap(x, y);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	add(i, j, x, y);
	while(!q.empty()){
		int i, j, qx, qy;
		tie(i, j, qx, qy) = q.front();
		q.pop();
		add(i, j-1, qx, qy-1); 				
		add(i, j+1, qx-1, qy);
	}
	printf("%d\n", res);
}

