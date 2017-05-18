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

const int MAXN = 312345;

int n, m, k;

vector<int> adj[MAXN];
set<int> s[MAXN];

set<int> q;

int cor[MAXN], mx;
int mrk[MAXN];

void go(int u, int p){
	int c = 1;
	for(auto &it: q){
		if(s.find(it) == s.end()){
			cor[it] = 0;
			q.erase(it);
		}
	}
	for(int i: s[u]){
		if(q.find(i) == q.end()){
			while(cor[c] == 1)
				c++;
			cor[i] = q.size()+1;
			mrk[q.size()+1] = 1;
			mx = max(mx, cor[i]);
		}
	}
	for(int nxt: adj[u]){
		if(nxt == p) continue;
		
	}
}

int main (){
	mx = -1;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		while(t--){
			int val;
			scanf("%d", val);
			s[a].insert(val);
		}
	}
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	go(1, 1);
}
