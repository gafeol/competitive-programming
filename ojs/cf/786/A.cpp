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

const int MAXN = 7123;

int n, m, k[2];
int s[MAXN][2];
int deg[MAXN][2];

vector<int> adj[2];

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		s[a][0] = -1;
		s[a][1] = -1;
	}
	s[1][0] = 0;
	s[1][1] = 0;
	queue<pii> q;
	for(int t=0;t<2;t++){
		scanf("%d", &k[t]);
		for(int a=0;a<k[t];a++){
			int val;
			scanf("%d", &val);
			adj[t].pb(val);
		}
		q.push(pii(1, t));
	}
	for(int a=0;a<=n;a++){
		deg[a][0] = k[0];
		deg[a][1] = k[1];
	}
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int t = top.snd;
		int i = top.fst;
		debug("to em (%d %d)\n", i, t);
		for(int p: adj[t^1]){
			int ii = (i - 1 - p + n)%n + 1;
			if(s[i][t]){
				deg[ii][t^1]--;
				if(deg[ii][t^1] == 0){
					s[ii][t^1] = 0;
					debug("seta %d %d como perdedor\n", ii, t^1);
					q.push(pii(ii, t^1));
				}
			}
			else{
				if(deg[ii][t^1] > 0){
					deg[ii][t^1] = 0;
					s[ii][t^1] = 1;
					debug("seta %d %d como ganhador\n", ii, t^1);
					q.push(pii(ii, t^1));
				}
			}
		}
	}
	for(int t=0;t<2;t++){
		for(int a=2;a<=n;a++){
			if(s[a][t] == -1)
				printf("Loop ");
			else if(s[a][t] == 0)
				printf("Lose ");
			else
				printf("Win ");
		}
		printf("\n");
	}
}
