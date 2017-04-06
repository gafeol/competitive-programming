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

const int MAXN = 212345;

int n, m, k;

pii s[MAXN];

map<int, int> ind[MAXN], mrk[MAXN];

void go(int u, int v){
	mrk[u][v] = 1;
	mrk[v][u] = 1;
	int nxt = ind[u][v];
	if(mrk[nxt].find(u) == mrk[nxt].end())
		go(nxt, u);
}

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &k);
		for(int a=1;a<=n;a++){
			mrk[a].clear();
			ind[a].clear();
		}
		for(int a=1;a<=n;a++){
			int i, j, ii, jj;
			scanf("%d%d%d%d", &i, &ii, &j, &jj);
			s[a].fst = i;
			s[a].snd = ii;
			ind[a][i] = j;
			ind[a][j] = i;
			ind[a][ii] = jj;
			ind[a][jj] = ii;
		}
		go(k, s[k].fst);
		go(k, s[k].snd);
		int res = 0;
		for(int a=1;a<=n;a++){
			if(mrk[a].find(s[a].fst) == mrk[a].end()){
				res++;
				go(a, s[a].fst);
			}
			if(mrk[a].find(s[a].snd) == mrk[a].end()){
				res++;
				go(a, s[a].snd);
			}
		}
		printf("%d\n", res);
	}
}
