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

int n, m;
ll k;
int s[MAXN];

ll res[MAXN];

ll mul;

int touch;
ll p[MAXN];

int deg[MAXN], mrk[MAXN];

vector<int> adj[MAXN];

ll ans;

int cnt;

void go(int u){
	mrk[u] = 2;
	cnt++;
	for(int nxt: adj[u]){
		if(mrk[nxt] == 0)
			touch = 1;
		if(mrk[nxt] != 1) continue;
		go(nxt);
	}
}

void count(int u){
	mrk[u] = 2;
	cnt++;
	for(int nxt: adj[u]){
		if(mrk[nxt] != 0) continue;
		count(nxt);
	}
}

int main (){
	for_tests(t, tt){
		ans = 1;
		scanf("%d%lld", &n, &k);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			deg[a] = 0;
			mrk[a] = 0;
		}
		p[0] = 1;
		for(int a=1;a<=n;a++)
			p[a] = mod(p[a-1]*(k-1));
		res[2] = k*(k-1);
		res[3] = mod(k*(k-1)*(k-2));
		for(int a=3;a<=n;a++)
			res[a] = mod(mod((k-2)*res[a-1]) + mod((k-1)*res[a-2]));
		for(int a=0;a<n;a++){
			int x; 
			scanf("%d", &x);
			adj[a].pb(x);
			adj[x].pb(a);
			deg[a]++;
			deg[x]++;
		}
		queue<int> q;
		for(int a=0;a<n;a++){
			if(deg[a] == 1){
				q.push(a);
			}
		}
		while(!q.empty()){
			int u = q.front();
			mrk[u] = 1;
			q.pop();
			for(int nxt: adj[u]){
				deg[nxt]--;
				if(deg[nxt] == 1){
					q.push(nxt);
				}
			}
		}
		for(int a=0;a<n;a++){
			cnt = 0;
			touch = 0;
			if(mrk[a] == 1){
				go(a);
				if(touch)
					ans = mod(ans*p[cnt]);
				else
					ans = mod(ans*mod(p[cnt-1]*k));
			}
		}
		for(int a=0;a<n;a++){
			if(mrk[a] == 0){
				cnt = 0;
				count(a);
				ans = mod(ans*res[cnt]);
			}
		}
		printf("%lld\n", ans);
	}
}

