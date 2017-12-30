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

int deg[MAXN];
queue<int> q;
queue<int> h;

vector<int> adj[MAXN];

void add(int u){
	if(deg[u])
		return ;
	if(s[u] == 0)
		q.push(u);
	else
		h.push(u);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[j].pb(i);
		deg[i]++;
	}
	for(int a=0;a<n;a++)
		add(a);
	int cnt = 0;
	int res =0;
	while(cnt < n){
		while(!q.empty()){
			cnt++;
			int u = q.front();
			q.pop();
			for(int nxt: adj[u]){
				deg[nxt]--;
				add(nxt);
			}

		}
		if(cnt != n){
			res++;
			while(!h.empty()){
				cnt++;
				int u = h.front();
				h.pop();
				for(int nxt: adj[u]){
					deg[nxt]--;
					add(nxt);
				}
			}
		}
	}
	printf("%d\n", res);
}

