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
int s[MAXN];
int mrk[MAXN], d[MAXN][2];

vector<int> adj[MAXN];

void go(int v, int val){
	s[v] = val;
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(!mrk[nxt])
			go(nxt, val^1);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=2*n;a+=2){
		adj[a].pb(a+1);
		adj[a+1].pb(a);
	}
	for(int a=1;a<=n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		d[a][0] = i;
		d[a][1] = j;
	}
	for(int a=1;a<=2*n;a++){
		if(!mrk[a]){
			go(a, 0);
		}
	}
	for(int a=1;a<=n;a++){
		printf("%d %d\n", s[d[a][0]]+1, s[d[a][1]]+1);
	}
}
