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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

int M[MAXN][MAXN];

pii nxt[MAXN][MAXN];
pii pre[MAXN][MAXN];
pii cpy[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			pre[a][b] = pii(a, b);
			nxt[a][b] = pii(a, b);
		}
	}
	for(int a=0;a<k;a++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int i;
			scanf("%d", &i);
			i--;
			for(int j=0;j<m;j++){
				nxt[pre[i][j].fst][pre[i][j].snd] = pii(i, (j+m-1)%m);
				cpy[j] = pre[i][j];
				debug("nxt %d %d = %d %d\n", i, j, nxt[i][j].fst, nxt[i][j].snd);
			}
			for(int j=0;j<m;j++){
				pre[i][(j+m-1)%m] = cpy[j];
			}
		}
		else if(t == 2){
			int j;
			scanf("%d", &j);
			j--;
			for(int i=0;i<n;i++){
				cpy[i] = pre[i][j];
				nxt[pre[i][j].fst][pre[i][j].snd] = pii((i+n-1)%n, j);
				debug("nxt %d %d = %d %d\n", i, j, nxt[i][j].fst, nxt[i][j].snd);
			}
			for(int i=0;i<n;i++){
				pre[(i+n-1)%n][j] = cpy[i];
			}
		}
		else if(t == 3){
			int i, j, x;
			scanf("%d %d %d", &i, &j, &x);
			i--;j--;
			M[pre[i][j].fst][pre[i][j].snd] = x;
		}
		debug("NXT\n");
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				debug("(%d, %d) ", nxt[a][b].fst, nxt[a][b].snd);
			}
			debug("\n");
		}
		debug("\nPRE\n");
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				debug("(%d, %d) ", pre[a][b].fst, pre[a][b].snd);
			}
			debug("\n");
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			printf("%d ", M[a][b]);
		}
		printf("\n");
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			debug("(%d, %d) ", pre[a][b].fst, pre[a][b].snd);
		}
		debug("\n");
	}
}
