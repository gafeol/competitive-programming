#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<pii, ll> ppl;


#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123, MAXM = 11234;
const ll INF = 112345678901234;

int n, m, s, t, prv[MAXN];
ll L, d[MAXN];

vector<pil> adj[MAXN];
vector<pii> var, pth;
vector<int> ind;

vector<pair<pii, ll> > ar;

set<pii> q;

map<pii, int> iadj, indp, mrk;

void dijk(){
	prv[s] = -1;
	for(int a=0;a<n;a++){
		d[a] = INF;
	}
	d[s] = 0;
	q.insert(pii(0, s));
	while(!q.empty()){
		int u = q.begin()->snd;
		q.erase(q.begin());
		for(pii nxt: adj[u]){
			int v = nxt.fst;
			int c = nxt.snd;
			if(d[v] > d[u] + c){
				if(d[v] != INF)
					q.erase(pii(d[v], v));
				d[v] = d[u] + c;
				prv[v] = u;
				q.insert(pii(d[v], v));
			}
		}
	}
}

void fail(){
	puts("NO");
	exit(0);
}

void win(){
	puts("YES");
	for(ppl a: ar){
		printf("%d %d %lld\n", a.fst.fst, a.fst.snd, a.snd);
	}
	exit(0);
}


int main (){
	scanf("%d%d%lld%d%d", &n, &m, &L, &s, &t);
	for(int a=0;a<m;a++){
		int i, j;
		ll k;
		scanf("%d%d%lld", &i, &j, &k);
		indp[pii(i, j)] = a;
		indp[pii(j, i)] = a;
		ar.pb(ppl(pii(i, j), k!=0 ? k : 1));
		if(k != 0){
			adj[i].pb(pil(j, k));
			adj[j].pb(pil(i, k));
		}
		else{
			var.pb(pii(i, j));
			ind.pb(a);
		}
	}
	dijk();
	if(d[t] < L)
		fail();
	else if(d[t] == L){
		for(int a=0;a<var.size();a++){
			ar[ind[a]].snd = L+1;
		}
		win();
	}
	else{
		for(pii v: var){
			iadj[v] = adj[v.fst].size();
			iadj[pii(v.snd, v.fst)] = adj[v.snd].size();
			adj[v.fst].pb(pil(v.snd, 1ll));
			adj[v.snd].pb(pil(v.fst, 1ll));
		}
		dijk();
		if(d[t] < L){
			int u = t;
			while(prv[u] != -1){
				if(iadj.count(pii(prv[u], u))){
					pth.pb(pii(prv[u], u));
					mrk[pii(prv[u], u)] = 1;
					mrk[pii(u, prv[u])] = 1;
				}
				u = prv[u];
			}
			for(int a=0;a<var.size();a++){
				if(!mrk[var[a]]){
					ar[ind[a]].snd = L+1;
					adj[var[a].fst][iadj[var[a]]].snd = L+1;
					adj[var[a].snd][iadj[pii(var[a].snd, var[a].fst)]].snd = L+1;
				}

			}
			int i = 0;
			do{
				int u = pth[i].fst, v = pth[i].snd;
//				printf("adj[%d][%d] = (%d - > %d) %lld\n", u, iadj[pth[i]], u, adj[u][iadj[pth[i]]].fst, L-d[t]+1);
				adj[u][iadj[pth[i]]].snd = L - d[t] + 1;
//				printf("adj[%d][%d] = (%d -> %d) %lld\n", v, iadj[pii(v, u)], v, adj[v][iadj[pii(v, u)]].fst,  L-d[t]+1);
				adj[v][iadj[pii(v, u)]].snd = L - d[t] + 1;
				ar[indp[pth[i]]].snd = L - d[t] + 1;
				
//				printf("d[%d] %lld\n", t, d[t]);
				dijk();
//				printf("d[%d] %lld\n", t, d[t]);
				i++;
			} while(d[t] != L);
			win();
		}
		else if(d[t] == L)
			win();
		else
			fail();
	}
}
