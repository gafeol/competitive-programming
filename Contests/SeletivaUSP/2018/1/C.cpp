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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
ll s[MAXN];

ll M[10][10];
ll base[10][10];
ll aux[10][10];
ll mul[10][10];
ll res = 0;


void expo(ll e){
	if(e == 0){
		for(int a=0;a<=n;a++)
			for(int b=0;b<=n;b++)
				M[a][b] = (a == b);
		return ;
	}
	expo(e/2ll);
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			for(int c=0;c<=n;c++){
				aux[a][b] = mod(aux[a][b] + M[a][c]*M[c][b]);
			}
		}
	}
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			M[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}

	if((e&1)){
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				for(int c=0;c<=n;c++){
					aux[a][b] = mod(aux[a][b] + M[a][c]*base[c][b]);
				}
			}
		}
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				M[a][b] = aux[a][b];
				aux[a][b] = 0;
			}
		}
	}
}

void mult(){
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			for(int c=0;c<=n;c++){
				aux[a][b] = mod(aux[a][b] + mul[a][c]*M[c][b]);
			}
		}
	}
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			M[a][b] = aux[a][b];
			aux[a][b] = 0;
		}
	}
}

ll ini[MAXN*2];

void print(){
	return ;
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			debug("%lld ", M[a][b]);
		}
		debug("\n");
	}
}

int main (){
	for_tests(t, tt){
		ll e;
		res = 0;
		scanf("%lld%d%d", &e, &n, &k);
		for(int a=0;a<n;a++)
			scanf("%lld", ini+a);
		for(int a=0;a<n;a++)
			scanf("%lld", s+a);

		int nk = 0;	
		for(int a=0;a<n;a++){
			if((a+1)%k == 0){
				res = mod(res + ini[a]);
				nk++;
				if(nk == e) break;
			}
		}
		if(nk == e){
			printf("%lld\n", res);
			continue;
		}

		int tam = n;
		if(n%k != 0){
			while(tam%k != 0){
				ini[tam] = 0;
				for(int a = 0;a<n;a++){
					ini[tam] = mod(ini[tam] + s[a]*ini[tam-1-a]);
				}
				debug("ini[%d] = %lld\n", tam, ini[tam]);
				tam++;
			}
			nk++;
			res = mod(res + ini[tam-1]);
		}
		if(nk == e){
			printf("%lld\n", res);
			continue;
		}
		ll sres = res;

		debug("nk %d res %lld\n", nk, res);

		for(int a=0;a<n+1;a++)
			base[0][a] = (a==0);
		for(int a=0;a<n+1;a++)
			base[1][a] = (a == 0 ? 0 : s[a-1]);
		for(int b=2;b<n+1;b++){
			for(int a=0;a<n+1;a++){
				base[b][a] = (b-1 == a);
			}
		}
		/*
		debug("before\n");
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				debug("%lld ", base[a][b]);
			}
			debug("\n");
		}
		debug("expo %d\n", k-1); 
		*/
		expo(k-1);

		debug("after\n");
		print();
		for(int a=0;a<n+1;a++){
			mul[0][a] = (a==0 ? 1 : s[a-1]);
		}
		for(int a=0;a<n+1;a++)
			mul[1][a] = (a == 0 ? 0 : s[a-1]);
		for(int b=2;b<n+1;b++)
			for(int a=0;a<n+1;a++)
				mul[b][a] = (b-1 == a);
		mult();
		/*
		 debug("after mult\n");
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				debug("%lld ", M[a][b]);
			}
			debug("\n");
		} 
		*/
		for(int a=0;a<=n;a++)
			for(int b=0;b<=n;b++)
				base[a][b] = M[a][b];
		debug("bef\n");
		print();
		debug("expo %lld\n", e-nk);
		expo(e - nk);
		debug("aft\n");
		print();
		ll res = mod(sres*M[0][0]);
		// faz a soma do sum, primeiro parametro da matriz
		for(int a=1;a<=n;a++){
			res = mod(res + ini[tam-a]*M[0][a]);
		}
		printf("%lld\n", res);
	}
}

