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
const ll modn = 10000;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 145;

int n, m, k;
int s[MAXN];

ll adj[MAXN][MAXN];

ll res[MAXN][MAXN];
ll aux[MAXN][MAXN];

void mult(int t){
	if(t == 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				aux[a][b] = 0;
				for(int c=0;c<n;c++){
					aux[a][b] = mod(aux[a][b] + res[a][c]*res[c][b]);
				}
			}
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				res[a][b] = aux[a][b];
			}
		}


	}
	else{
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				aux[a][b] = 0;
				for(int c=0;c<n;c++){
					aux[a][b] = mod(aux[a][b] + res[a][c]*adj[c][b]);
				}
			}
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				res[a][b] = aux[a][b];
			}
		}
	}
}

void expo(int e){
	if(e == 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				res[a][b] = (a == b);
			}
		}
		return ;
	}
	expo(e/2);
	mult(0);
	if((e&1))
		mult(1);
}

int main (){
	scanf("%d%d", &n, &m);
	int s, t;
	scanf("%d %d", &s, &t);
	s--;
	t--;
	for(int a=0;a<n;a++){	
		for(int b=0;b<4;b++){
			int j;
			scanf("%d", &j);
			j--;
			adj[a][j]++;
		}
	}
	expo(m);
	printf("%lld\n", res[s][t]);
}

