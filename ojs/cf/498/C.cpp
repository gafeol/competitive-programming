#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
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

int n, m, k, ans, res;
int s[MAXN], criv[112345], v[MAXN], deg[MAXN], dg[MAXN], mrk[MAXN];

vector<int> pri, adj[MAXN];

set<int> p;

void div(int pr){
	for(int a=1;a<=n;a++){
		mrk[a] = 0;
		deg[a] = dg[a];
		v[a] = 0;
		int val = s[a];
		while(val%pr == 0){
			v[a]++;
			val /= pr;
		}
	}
}

void go(int u){
	mrk[u] = 1;
	for(int nxt: adj[u]){
		int aux = min(v[u], v[nxt]);
		ans += aux;
		v[u] -= aux;
		v[nxt] -= aux;
		if(mrk[nxt]) continue;
		go(nxt);
	}
}

queue<int> q;
main (){
	for(int i=2;i<112345;i++){
		if(criv[i]) continue;
		pri.pb(i);
		for(ll j = i;i * j < 112345;j++){
			criv[i*j] = 1;
		}
	}
	scanf("%lld%lld", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
		int val = s[a];
		debug("analisa %lld\n", val);
		for(int pr: pri){
			if(val%pr == 0){
				p.insert(pr);
				debug("eh dividod por %lld\n", pr);
			}
			while(val%pr == 0){
				val /= pr;
			}
		}
		debug("e sobra %lld\n", val);
		if(val != 1)
			p.insert(val);
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%lld %lld", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		dg[j]++;
		dg[i]++;
	}


	while(!p.empty()){
		int pr = *p.begin();
		debug("pr %lld\n", pr);
		p.erase(pr);
		div(pr);
		for(int a=1;a<=n;a++){
			if(v[a] == 0){
				mrk[a] = 1;
				for(int nxt: adj[a]){
					deg[nxt]--;
				}
			}
		}
		for(int a=1;a<=n;a++){
			if(deg[a] <= 1 && !mrk[a]){
				q.push(a);
				mrk[a] = 1;
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int nxt: adj[u]){
				int aux = min(v[u], v[nxt]);
				ans += aux;
				v[u] -= aux;
				v[nxt] -= aux;
				deg[nxt]--;
				if(deg[nxt] <= 1 && mrk[nxt] == 0){
					mrk[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		for(int a=1;a<=n;a++){
			if(mrk[a] == 0){
				go(a);
			}
		}
	}
	printf("%lld\n", ans);
}
