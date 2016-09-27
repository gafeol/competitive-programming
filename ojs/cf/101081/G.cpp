#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123;

int n, m, k;
ll adj[MAXN][MAXN], ini[MAXN][MAXN], aux[MAXN][MAXN], maux[MAXN][MAXN];
ll mrk[MAXN][MAXN];

void mulm(ll A[MAXN][MAXN], ll B[MAXN][MAXN]){
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			aux[a][b] = 0;
			maux[a][b]  = 0;
			for(int c=1;c<=n;c++){
				aux[a][b] = mod(aux[a][b] + mod(A[c][b]*B[a][c]));
				maux[a][b] = ((maux[a][b] + A[c][b]*B[a][c]) > 0);
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			A[a][b] = aux[a][b];
			mrk[a][b] = maux[a][b];
			maux[a][b]  = 0;
			aux[a][b] = 0;
		}
	}
}

void exp(int e){
	if(e == 0 || e == 1)
		return;
	exp(e/2);
	mulm(adj, adj);
	if(e&1)
		mulm(adj, ini);
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);	
		adj[i][j]++;
		adj[j][i]++;
		ini[i][j]++;
		ini[j][i]++;
		mrk[i][j] = 1;
		mrk[j][i] = 1;
	}
	exp(k);
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			if(mrk[a][b] != 0)
				printf("%lld ", adj[a][b]);
			else
				printf("-1 ");
		}
		printf("\n");
	}
}
