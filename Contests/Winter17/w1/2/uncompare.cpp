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
char s[MAXN];
int ans[MAXN];

vector<int> adj[MAXN];

int deg[MAXN];
queue<int> q;

int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int a=0;a<n;a++){
		if(s[a] == '<'){
			adj[a].pb(a+1);
			deg[a+1]++;
		}
		else{
			adj[a+1].pb(a);
			deg[a]++;
		}
	}

	for(int a=0;a<n+1;a++){
		if(deg[a] == 0)
			q.push(a);
	}

	int res = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans[u] = res++;
		for(int nxt: adj[u]){
			deg[nxt]--;
			if(deg[nxt] == 0)
				q.push(nxt);
		}
	}
	for(int a=0;a<n+1;a++){
		printf("%d ", ans[a]);
	}
}
