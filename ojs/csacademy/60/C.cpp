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
vector<int> adj[MAXN];
vector<int> s[MAXN];

queue<int> q;
int z = 1;
int mrk[MAXN];
int deg[MAXN];

void add(int i, int j){
	adj[i].pb(j);
	deg[j]++;
}
int ini[MAXN], res[MAXN];

void fz(int d){
	if(z == 0) return ;
	if(!ini[d]){
		res[d] = 0;
		z = 0;
	}
}

void fail(){
	puts("-1");
	exit(0);
}

int main (){
	memset(res, -1, sizeof(res));
	scanf("%d%d%d", &n, &k, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			int x;
			scanf("%d", &x);
			s[a].pb(x);
		}
	}
	for(int a=0;a<n;a++){
		ini[s[a][0]] = 1;
		if(a < n-1){
			int i = 0;
			for(i=0;i<m;i++)
				if(s[a][i] != s[a+1][i]) break;	
			if(i == m){
				fail();
			}
			add(s[a][i], s[a+1][i]);
		}
	}
	for(int d=0;d<k;d++){
		if(deg[d] == 0){
			fz(d);
			q.push(d);
		}
	}
	if(z) fail();
	int cnt = 1;
	while(!q.empty()){
		int d = q.front();
		if(res[d] == -1) res[d]= cnt++;
		q.pop();
		for(int nxt: adj[d]){
			deg[nxt]--;
			if(deg[nxt] == 0){
				q.push(nxt);
			}

		}
	}
	for(int a=0;a<k;a++){
		if(deg[a] != 0)
			fail();
	}
	for(int a=0;a<k;a++){
		if(res[a] == -1){
			res[a] = cnt++;
		}
		printf("%d ", res[a]);
	}
	puts("");
}

