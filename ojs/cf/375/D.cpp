

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
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

const int MAXN = 212345, SQRT = 512;

int n, m, k;
int c[MAXN], L[MAXN], R[MAXN], s[4*MAXN];
int res[MAXN];

int cnt[MAXN], inv[MAXN], suff[MAXN];

vector<int> v, adj[MAXN];
vector<ppp> q[SQRT];

void go(int u, int p){
	L[u] = v.size();
	v.pb(u);
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		go(nxt, u);
	}
	R[u] = v.size();
	v.pb(u);
}


bool cmp(ppp a, ppp b){
	return a.fst.snd < b.fst.snd;
}

void add(int i){
	if(!s[i]) return;
	cnt[s[i]]++;
	suff[cnt[s[i]]]++;
}

void rmv(int i){
	if(!s[i]) return;
	suff[cnt[s[i]]]--;
	cnt[s[i]]--;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%d", &c[a]);
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}	
	go(1, 1);
	for(int a=1;a<=n;a++){
		s[L[a]] = c[a];
	}
	
	int tam = v.size();
	int sq = sqrt(tam);
	int mx = 0;
	for(int a=0;a<m;a++){
		int u;
		scanf("%d %d", &u, &k);
		int l = L[u];
		int r = R[u];
		q[l/sq].pb(ppp(pii(l, r), pii(k, a)));
		mx = max(mx, l/sq);
	}
	for(int a=0;a<=mx;a++){
		sort(q[a].begin(), q[a].end(), cmp);
		int i = 0;
		int j = -1;
		for(ppp qry: q[a]){
			while(j < qry.fst.snd){
				add(j+1);
				j++;
			}
			while(i > qry.fst.fst){
				add(i-1);
				i--;
			}
			while(i < qry.fst.fst){
				rmv(i);
				i++;
			}
			res[qry.snd.snd] = suff[qry.snd.fst];
		}
		while(i <= j){
			rmv(i);
			i++;
		}
	}
	for(int a=0;a<m;a++){
		printf("%d\n", res[a]);
	}
}	
