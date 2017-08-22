#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mt make_tuple
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 55, INF = 0x3f3f3f3f;

int n, m, k;
int ii, jj;

int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

char M[MAXN][MAXN], s[MAXN], mrk[MAXN][MAXN][MAXN];

int d[MAXN][MAXN][MAXN];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '#'); 
}

int id(char c){
	if(c == 'R')
		return 0;
	if(c == 'L')
		return 1;
	if(c == 'U')
		return 2;
	return 3;
}

set<tuple<int, int, int, int> > q;

void relax(int ni, int nj, int k, int dist){
	if(dist > d[ni][nj][k]) return;
	if(d[ni][nj][k] != INF){
		q.erase(mt(d[ni][nj][k], ni, nj, k));
		debug("erase %d %d %d %d\n", d[ni][nj][k], ni, nj, k);
	}

	d[ni][nj][k] = min(d[ni][nj][k], dist);
	q.insert(mt(d[ni][nj][k], ni, nj,k));
	debug("insert%d %d %d %d\n", d[ni][nj][k], ni, nj, k);
}

int main(){
	scanf("%d %d", &n, &m);
	int ii, ij, fi, fj; 
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'R'){
				ii = a;
				ij = b;
			}
			else if(M[a][b] == 'E'){
				fi = a;
				fj = b;
			}
		}
	}
	scanf(" %s", s);
	int tam = strlen(s);
	memset(d, INF, sizeof(d));
	q.insert(mt(0, ii, ij, 0));
	d[ii][ij][0] = 0;
	while(!q.empty()){
		tuple<int, int, int, int> top = *q.begin();
		q.erase(q.begin());
		int _d, i, j, k;
		tie(_d, i, j, k) = top;
		debug("i %d j %d k %d\n", i, j, k);
		debug("d %d _d %d\n", d[i][j][k], _d);
		if(k < tam){
			int di = id(s[k]);
			int ni = i + vi[di];
			int nj = j + vj[di];
			if(valid(ni, nj))
				relax(ni, nj, k+1, d[i][j][k]);
			else
				relax(i, j, k+1, d[i][j][k]);
		}

		for(int di=0;di<4;di++){
			int ni = i + vi[di];
			int nj = j + vj[di];
			if(valid(ni, nj))
				relax(ni, nj, k, 1+d[i][j][k]);
		}
	}
	int ans = INF;
	/*for(int a=0;a<tam;a++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ", d[i][j][a]);
			}
			puts("");
		}
		puts("");
	}*/
	for(int a=0;a<=tam;a++){
		ans = min(ans, d[fi][fj][a]);
		debug("sz %d d %d\n", a, d[fi][fj][a]);
	}
	printf("%d\n", ans);
}
