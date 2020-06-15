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

const int MAXN = 66;
const int INF = 0x3f3f3f3f;
const int CTE = 12;

int n, m, k;
int s[MAXN];

int dp[MAXN][MAXN][24][24];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int nxti, nxtj;
int endi, endj, inii, inij;


int sign(int x){
	return (x > 0) - (x < 0);
}

int cross(pii a, pii b, pii c){
	pii u = pii(c.fst - a.fst, c.snd - a.snd);
	pii v = pii(b.fst - a.fst, b.snd - a.snd);
	return u.fst*v.snd - u.snd*v.fst;
}

bool btw(pii a, pii b, pii c){
	pii u = pii(b.fst - c.fst, b.snd - c.snd);
	pii v = pii(a.fst - c.fst, a.snd - c.snd);
	return cross(a, b, c) == 0 && (u.fst * v.fst + u.snd * v.snd <= 0);
}

bool inter_seg(pii a, pii b, pii c, pii d){

	if(btw(a, b, c) || btw(a, b, d) || btw(c, d, a) || btw(c, d, b)) {
		printf("(%d %d) - (%d %d), (%d %d) - (%d %d)\n", a.fst, a.snd, b.fst, b.snd, c.fst, c.snd, d.fst, d.snd); 
		return true;
	}
	if(sign(cross(a, b, c)) * sign(cross(a, b, d)) == -1 && sign(cross(c, d, a)) * sign(cross(c, d, b)) == -1){
		printf("(%d %d) - (%d %d), (%d %d) - (%d %d)\n", a.fst, a.snd, b.fst, b.snd, c.fst, c.snd, d.fst, d.snd); 
		return true;
	}
	return false;
}


int f;
pii w[MAXN][2];

bool nxt(int i, int j, int vi, int vj){
	nxti = i + vi;	
	nxtj = j + vj;

	for(int a=0;a<f;a++){
		if(inter_seg(pii(i, j), pii(nxti, nxtj), w[a][0], w[a][1])){
			return false;		
		}
	}
	return true;
}



int go(int i, int j, int vi, int vj){
	if(i >= n || j >= m || i < 0 || j < 0) return INF;

	vi += CTE;
	vj += CTE;

	int &r = dp[i][j][vi][vj];

	vi -= CTE;
	vj -= CTE;

	if(i == endi && j == endj && vi == 0 && vj == 0)
		return r = 0;
	if(r != -1) return r;
	r = INF;
	if(nxt(i, j, vi+1, vj))
		r = min(r, 1+go(nxti, nxtj, vi+1, vj));
	if(nxt(i, j, vi-1, vj))
		r = min(r, 1+go(nxti, nxtj, vi-1, vj));
	if(nxt(i, j, vi, vj+1))
		r = min(r, 1+go(nxti, nxtj, vi, vj+1));
	if(nxt(i, j, vi, vj-1))
		r = min(r, 1+go(nxti, nxtj, vi, vj-1));
	if(nxt(i, j, vi, vj))
		r = min(r, 1+go(nxti, nxtj, vi, vj));
	
	return r;
}



int main (){
	while(scanf("%d%d", &m, &n) != EOF){ 
		scanf("%d%d%d%d", &inij, &inii, &endj, &endi);
		scanf("%d", &f);
		for(int a=0;a<f;a++){
			scanf("%d%d%d%d", &w[a][0].snd, &w[a][0].fst, &w[a][1].snd, &w[a][1].fst);	
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(inii, inij, 0, 0));
	}
}


