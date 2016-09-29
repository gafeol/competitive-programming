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

const int MAXN = 212345, MASK = (1<<6) + 2;

int m, k;
ll n;
ll dp[MASK][MASK], keep[MASK][MASK], aux[MASK][MASK];

void mulm(ll A[MASK][MASK], ll B[MASK][MASK]){
	for(int a=0;a<(1<<m);a++){
		for(int b=0;b<(1<<m);b++){
			aux[a][b] = 0;
			for(int c=0;c<(1<<m);c++){
				aux[a][b] = mod(aux[a][b] + A[c][b]*B[a][c]);
			}
		}
	}
	for(int a=0;a<(1<<m);a++){
		for(int b=0;b<(1<<m);b++){
			A[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}
}

void id(ll A[MASK][MASK]){
	for(int a=0;a<(1<<m);a++){
		for(int b=0;b<(1<<m);b++){
			A[a][b] = (a == b);
		}
	}
}

void expo(ll e){
	if(e == 0){
		id(dp);
		return;
	}
	id(keep);
	while(e > 1){
		if(e&1ll)
			mulm(keep, dp);
		mulm(dp, dp);
		e >>= 1;
	}
	mulm(dp, keep);
}

int main (){
	scanf("%d%lld", &m, &n);
	for(int a=0;a<(1<<m);a++){
		for(int b=0;b<(1<<m);b++){
			int z = 0, res = 1;
			for(int d =1;d<m;d++){
				if((a&(1<<d)) == (b&(1<<d)) && (a&(1<<(d-1))) == (b&(1<<(d-1))) && ((a&(1<<d))>>1) == (a&(1<<(d-1)))){
					res = 0;
					break;
				}
			}
			dp[a][b] = res;
		}
	}
	expo(n-1);
	ll ans = 0;
	for(int a=0;a<(1<<m);a++){
		for(int b=0;b<(1<<m);b++){
			ans = mod(ans + dp[a][b]);
		}
	}
	printf("%lld\n", ans);
}
