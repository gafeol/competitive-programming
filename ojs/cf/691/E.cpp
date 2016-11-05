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

const int MAXN = 112;

int n;
ll m, k;
ll s[MAXN];
ll base[MAXN][MAXN];
ll M[MAXN][MAXN];
ll aux[MAXN][MAXN];
ll ini[MAXN][MAXN];

void cpy(ll A[MAXN][MAXN], ll B[MAXN][MAXN]){
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			A[a][b] = B[a][b];
		}
	}
}

void mult(ll A[MAXN][MAXN], ll B[MAXN][MAXN]){
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			aux[a][b] = 0;
			for(int c=0;c<n;c++){
				aux[a][b] = mod(aux[a][b] + mod(A[a][c]*B[c][b]));
			}
		}
	}
	cpy(A, aux);
}

void expo(ll e){
	if(e == 0ll){
		cpy(M, ini);
		return ;
	}
	if(e == 1ll)
		return;
	expo(e/2ll);
	mult(M, M);
	if(e&1ll)
		mult(M, base);
}

int main (){
	scanf("%d%lld", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			ini[a][b] = (a==b);
		}
	}
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);	
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(__builtin_popcountll(s[a]^s[b])%3ll == 0ll)
				base[a][b] = M[a][b] = 1;
		}
	}
	expo(m-1ll);
	ll sum = 0;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			sum = mod(sum + M[a][b]);
		}
	}
	printf("%lld\n", sum);
}
