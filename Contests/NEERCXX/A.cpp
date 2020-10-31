
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

const int MAXN = 212;

int n;

int l[MAXN], r[MAXN], L[MAXN], R[MAXN];
int sz[MAXN], p[MAXN];

set<int> lef, rig;

int raiz(int u){
	if(p[u] == u) return u;
	return p[u] = raiz(p[u]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return ;
	if(sz[i] < sz[j])
		swap(i, j);
	p[j] = i;
	sz[i] += sz[j];	
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d %d", &l[a], &r[a]);
		if(l[a] != 0)
			join(l[a], a);
		if(r[a] != 0)
			join(r[a], a);
	}
	set<int> g;
	for(int a=1;a<=n;a++){
		if(l[a] == 0)
			L[raiz(a)] = a;
		if(r[a] == 0)
			R[raiz(a)] = a;
		g.insert(raiz(a));
	}
	int ult = 0;
	while(!g.empty()){
		int u = *g.begin();
		int left = L[u];
		r[ult] = left;
		l[left] = ult;
		ult = R[u];
		g.erase(g.begin());
	}
	for(int a=1;a<=n;a++){
		printf("%d %d\n", l[a], r[a]);
	}
}
