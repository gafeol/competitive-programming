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

const int MAXN = 2;

ll A, B, x, n, k;
ll m[MAXN][MAXN], base[MAXN][MAXN], aux[MAXN][MAXN];
int s[MAXN];

void expo(ll e){
	if(e == 1){
		return;
	}
	expo(e/2ll);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			aux[i][j] = 0;
			for(int k=0;k<2;k++){
				aux[i][j] = mod(aux[i][j] + m[k][j]*m[i][k]);
			}
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			m[i][j] = aux[i][j];
			debug("bota %lld no %d %d\n", aux[i][j], i, j);
		}
	}
	if(e&1){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				aux[i][j] = 0;
				for(int k=0;k<2;k++){
					aux[i][j] = mod(aux[i][j] + m[k][j]*base[i][k]);
				}
			}
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				m[i][j] = aux[i][j];
			}
		}
	}
}

void printm(){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			debug("%lld ", m[a][b]);
		}
		debug("\n");
	}
}

int main (){
	scanf("%lld%lld%lld%lld", &A, &B, &n, &x);
	base[0][0] = A;
	base[0][1] = 1;
	base[1][0] = 0;
	base[1][1]= 1;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
			m[a][b] = base[a][b];
	expo(n);
	printm();
	printf("%lld\n", mod(m[0][0]*x + m[0][1]*B));
}
