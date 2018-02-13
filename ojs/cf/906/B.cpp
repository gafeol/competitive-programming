#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN], mrk[MAXN];

int **res, **M;

int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void put(int u, int pos){
	debug("put %d %d\n", u, pos);
	int i = (u-1)/m, j = (u-1)%m;
	int ii = (pos-1)/m, jj = (pos-1)%m;
	for(int d=0;d<4;d++){
		if(!valid(i+vi[d], j+vj[d])) continue;
		for(int dd=0;dd<4;dd++){
			if(!valid(ii+vi[dd], jj+vj[dd])) continue;
			debug("testa %d %d %d %d %d %d\n", i+vi[d], j+vj[d], M[i+vi[d]][j+vj[d]], ii+vi[dd], jj+vj[dd], res[ii+vi[dd]][jj+vj[dd]]);
			if(M[i+vi[d]][j+vj[d]] == res[ii+vi[dd]][jj+vj[dd]]){
				puts("NO");
				exit(0);
			}
		}
	}
	res[ii][jj] = u;
	mrk[u] = 1;
	debug("res %d %d = %d\n", ii, jj, u);
}

int main (){
	scanf("%d%d", &n, &m);
	res = (int**) malloc(n*sizeof(int*));
	M = (int**) malloc(n*sizeof(int*));
	for(int a=0;a<n;a++){
		res[a] = (int*) malloc(m*sizeof(int));
		M[a] = (int*) malloc(m*sizeof(int));
		for(int b=0;b<m;b++){
			M[a][b] = a*m + b + 1; 
			res[a][b] = -1;
		}
	}
	int deg = 1;
	int ini = 1;
	int fim = n*m;
	for(int i=1;i<=n;i++){
		while(mrk[ini] != 0)
			ini++;
		while(mrk[fim] != 0)
			fim--;
		int u;
		if((i&1))
			u = ini;
		else
			u = fim;
			
		debug("bota u %d\n", u);
		while(u > 0 && u <= n*m){
			put(u, deg);	
			deg++;
			if((i&1))
				u += n;
			else
				u -= n;
		}

	}
	puts("YES");
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			printf("%d ", res[a][b]);
		}
		puts("");
	}
}

