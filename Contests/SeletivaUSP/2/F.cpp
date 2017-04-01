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
int deg[MAXN], snk[MAXN];
int mrk[MAXN], sz[MAXN];
queue<int> q;
vector<int> v;

void go(int u){
	h[u] = 1;
	mrk[u] = 1;
	int mx = 0;
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		go(nxt);
		mx = max(h[nxt], mx);
	}
	h[u] += mx;
}

void add(int u, int d){
	mrk2[u] = 1;
	int mx = 0, im = -1;
	for(int nxt: adj[u]){
		if(mrk2[nxt]) continue;
		if(h[nxt] > mx){
			mx = h[nxt];
			im = nxt;
		}
	}
	if(im != -1)
		add(im, d+1);
	for(int nxt: adj[u]){
		if(mrk2[nxt] || nxt == im) continue;
		add(nxt, 1);
	}

	if(im == -1){
		v.pb(d);
	}
}

int mxd, umx;

void maxd(int u, int d){
	mrk[u] = 1;
	if(d > mxd){
		mxd = d;
		umx = u;
	}
	for(int nxt: adj[u]){
		if(mrk[nxt]) continue;
		maxd(nxt);
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d%d", &n, &m, &k);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			adj[i].pb(j);
			adj[j].pb(i);
			deg[i]++;
			deg[j]++;
		}

		for(int a=1;a<=n;a++){
			if(deg <= 1)
				q.push(a);
		}
		int afun = 0;
		while(!q.empty()){
			int u = q.front();
			snk[u] = 1;
			afun++;
			q.pop();
			for(int nxt: adj[u]){
				deg[nxt]--;
				if(deg[nxt] == 1)
					q.push(nxt);
			}
		}
		for(int a=1;a<=n;a++){
			if(!snk[a]){
				mrk[a] = 1;
				for(int nxt: adj[a]){
					if(!snk[nxt]) continue;
					go(nxt);
					add(nxt, 1);
					sort(v.begin(), v.end());
					for(int i=0;i<v.size();i++){
						bota(v[i], i+1);
					}
					v.clear();
				}
			}
		}
		for(int a=1;a<=n;a++){
			if(snk[a] && !mrk[a]){
				maxd(a, 0);
				int i = umx;
				maxd(umx, 0);
				memset(mrk, 0, sizeof(mrk));
				int j = imx;
				bota(
			}
		}
	}
}
