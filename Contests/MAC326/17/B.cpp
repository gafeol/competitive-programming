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

const int MAXN = 6023;

int n, m, k;

char M[MAXN][MAXN];

int l[MAXN][MAXN], r[MAXN][MAXN];
int dd[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool valid(int a, int b){
	return (a >= 0 && b >= 0 && a < n && b < m);
}

int gor(int a, int b){
	if(!valid(a, b) || M[a][b] != 'z') return 0;	
	if(r[a][b] != -1)
		return r[a][b];
	return r[a][b] = 1 + gor(a, b+1);
}

int gol(int a, int b){
	if(!valid(a, b) || M[a][b] != 'z') return 0;	
	if(l[a][b] != -1)
		return l[a][b];
	return l[a][b] = 1 + gol(a, b-1);
}

int god(int a, int b){
	if(!valid(a, b) || M[a][b] != 'z') return 0;
	if(dd[a][b] != -1)
		return dd[a][b];
	return dd[a][b] = 1 + god(a+1, b-1);
}

vector<int> put[MAXN];

void cons(int i, int j, int mx){
	if(!valid(i, j)) return ;	
	if(M[i][j] == 'z'){
		int jj = min(mx, j+gor(i, j)-1);
		put[jj].pb(i);	
		//printf("cons i %d j %d put %d %d\n", i, j, jj, i);

	}
	cons(i+1, j-1, mx);
}

int bit[MAXN];

void upd(int x, int val){
	x += 2;
	while(x < MAXN){
		bit[x] += val;
		x += (x&-x);
	}
}

int qry(int x){
	x+=2; 
	int ans = 0;
	x = min(MAXN-1, x);
	while(x > 0){
		ans += bit[x];
		x -= (x&-x);
	}
	return ans;
}

ll go(int i, int j){
	if(!valid(i, j)) return 0;

	ll ans = 0;
	for(int x: put[j]){
		//printf("upd %d\n", x);
		upd(x, 1);
	}
	if(M[i][j] == 'z'){
		int sz = min(l[i][j]-1, dd[i][j]-1);
		//printf("i %d j %d sz %d\n", i, j, sz);
		ans = qry(i + sz) - qry(i);
		//printf("ans %d\n", ans);
	}
	
	return ans + go(i+1, j-1);
}

int main (){
	scanf("%d%d", &n, &m);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	memset(dd, -1, sizeof(dd));
	ll res = 0;
	for(int a=0;a<n;a++){
		getchar();
		for(int b=0;b<m;b++){
			M[a][b] = getchar();
			res += (M[a][b] == 'z');
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			r[a][b] = gor(a, b);		
			l[a][b] = gol(a, b);
			dd[a][b] = god(a, b);
		}
	}
	for(int b=0;b<m;b++){
		for(int a=0;a<m;a++)
			put[a].clear();
		for(int a=0;a<=n+10;a++)
			bit[a] = 0;
		cons(0, b, b);
		ll ores = res;
		res += go(0, b);
	//	printf("go 0 %d: %lld\n", b, res - ores);
	}
	for(int a=1;a<n;a++){
		for(int a=0;a<m;a++)
			put[a].clear();
		for(int a=0;a<=n+10;a++)
			bit[a] = 0;
		cons(a, m-1, m-1);
		ll ores = res;
		res += go(a, m-1);
	//	printf("go %d %d: %lld\n", a, m-1, res - ores);
	}
	printf("%lld\n", res);
}

