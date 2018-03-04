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

vector<int> adj[MAXN];
int p[MAXN];

queue<int> q[2]; 

int go(int u){
	int h = 0;
	q[h].push(u);
	int res = 0;
	while(!q[h].empty()){
		res += (q[h].size())%2;
		while(!q[h].empty()){
			u = q[h].front();
			q[h].pop();
			for(int nxt: adj[u])
				q[h^1].push(nxt);
		}
		h = (h^1);
	}
	return res;
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		scanf("%d", p+a);
		adj[p[a]].pb(a);
	}
	printf("%d\n", go(1));
}

