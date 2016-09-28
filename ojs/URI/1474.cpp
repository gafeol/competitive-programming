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
const ll modn = 1000000;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll n, l, k;

ll M[2][2], aux[2][2], ini[2][2];

void cpy(ll u[2][2], ll v[2][2]){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			u[a][b] = v[a][b];
		}
	}
}

void print(ll A[2][2]){
//	for(int a=0;a<2;a++){
///		for(int b=0;b<2;b++){
//			printf("%lld ", A[a][b]);
//		}
//		putchar('\n');
//	}
}

void mulm(ll u[2][2], ll v[2][2]){
//	printf("mult\n");
	print(u);
	print(v);
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + u[c][b]*v[a][c]);
			}
		}
	}
	cpy(u, aux);
	print(u);
}


void expo(ll e){
	if(e == 0){
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				M[a][b] = (a == b);
			}
		}
		return ;
	}
	expo(e/2ll);
	mulm(M, M);
	if(e&1ll)
		mulm(M, ini);
}

void expoi(ll e){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = ini[a][b];
		}
	}
	if(e == 0){
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				M[a][b] = (a == b);
			}
		}
	}
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			ini[a][b] = (a == b);
		}
	}
	while(e > 1ll){
		if(e&1ll)
			mulm(ini, M);
		mulm(M, M);
		e /= 2ll;
	}
	print(M);
	mulm(M, ini);
}

int main (){
	while(scanf("%lld%lld%lld", &n, &k, &l)!= EOF){
		ll ml = mod(l), mk = mod(k);
		M[0][0] = mk;
		M[0][1] = ml;
		M[1][0] = 1;
		M[1][1] = 0;
		cpy(ini, M);
		if(n == 5){
			printf("%.6lld\n", mk);
			continue;
		}
		expo((n/5ll)-2);
		ll ans = mod(mod(M[0][0]*mod(ml + mk*mk)) + mod(M[0][1]*mk));
		printf("%.6lld\n", ans);
	}

}
