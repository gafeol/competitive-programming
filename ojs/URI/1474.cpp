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

void mulm(ll u[2][2], ll v[2][2]){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			aux[a][b] = 0;
			for(int c=0;c<2;c++){
				aux[a][b] = mod(aux[a][b] + u[c][b]*v[a][c]);
			}
		}
	}
	cpy(u, aux);
}

void print(ll A[2][2]){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			printf("%lld ", A[a][b]);
		}
		putchar('\n');
	}
}

void expo(ll e){
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			M[a][b] = (a==b);
		}
	}
	while(e > 0){
		mulm(M, M);
		if(e&1)
			mulm(M, ini);
		e <<= 1;
	}
	print(M);
}

int main (){
	scanf("%lld%lld%lld", &n, &l, &k);
	ll ml = mod(l), mk = mod(k);
	M[0][0] = mk;
	M[0][1] = ml;
	M[1][0] = 1;
	M[1][1] = 0;
	cpy(ini, M);
	expo((n/5ll)-1);
	ll ans = mod(mod(M[0][0]*mod(ml + mk*mk)) + mod(M[0][1]*mk));
	printf("%.6lld\n", ans);

}
