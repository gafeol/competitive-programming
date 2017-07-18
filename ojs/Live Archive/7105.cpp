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
const ll modn = 1000000009;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int MASK = (1<<5), MAXS = 100;

int n, m, k;

map<pii, int> ind;
int bf[MASK], af[MASK];

int deg;

int next(int a, int b){
	int bm = 0;
	for(int i=0;i<n;i++){
		if(a&(1<<i)){
			if(i > 1)
				bm |= (1<<(i-1));
			if(i < n-2)
				bm |= (1<<(i+1));
		}
		if(b&(1<<i)){
			if(i > 2)
				bm |= (1<<(i-2));
			if(i < n-3)
				bm |= (1<<(i+2));
		}
	}
	bm = ((1<<n)-1)^bm;
	return bm; 
}

bool valid(int a, int b){
	int nb = next(0, a), na = next(0, b);
	return ((nb|b) == nb && (na|a) == na);
}

ll M[MAXS][MAXS], base[MAXS][MAXS], aux[MAXS][MAXS];

void expo(ll e){
	if(e == 0) return ;
	expo(e/2);
	for(int a=0;a<deg;a++){
		for(int b=0;b<deg;b++){
			aux[a][b] = 0;
			for(int c=0;c<deg;c++){
				aux[a][b] = mod(aux[a][b] + M[a][c]*M[c][b]);
			}
		}
	}
	for(int a=0;a<deg;a++){
		for(int b=0;b<deg;b++){
			M[a][b] = aux[a][b];
		}
	}
	if(e&1){
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				aux[a][b] = 0;
				for(int c=0;c<deg;c++){
					aux[a][b] = mod(aux[a][b] + M[a][c]*base[c][b]);
				}
			}
		}
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				M[a][b] = aux[a][b];
			}
		}
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		deg = 0;
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<(1<<n);j++){
				if(valid(i, j)){
					bf[deg] = i;
					af[deg] = j;
					ind[pii(i, j)] = deg++;			
				}
			}
		}
		for(int i=0;i<deg;i++){
			for(int j=0;j<deg;j++){
				base[j][i] = 0;
				int nx = next(bf[i], af[i]);
				if(af[i] == bf[j] && (nx|af[j]) == nx)
					base[j][i] = 1;
			}
		}
		for(int i=0;i<deg;i++){
			for(int j=0;j<deg;j++){
				debug("%lld ", base[i][j]);
			}
			debug("\n");
		}
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				M[a][b] = (a==b);
			}
		}
		expo(m);
		for(int a=0;a<deg;a++){
			for(int b=0;b<deg;b++){
				debug("%lld ", M[a][b]);
			}
			debug("\n");
		}
		ll res = 0;
		for(int a=0;a<deg;a++){
			res = mod(res + M[a][0]);
		}
		printf("%lld\n", res);
	}
}
