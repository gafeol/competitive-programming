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

const int MAXN = 1123456;

int n, m, k;
int s[MAXN];
vector <int> adj[MAXN];
int pai[MAXN], sz[MAXN];

set<int> q[MAXN];

int raiz(int a){
	if(pai[a] == a) return a;
	return pai[a] = raiz(pai[a]);
}

void join(int aa, int bb){
	int a = raiz(aa);
	int b = raiz(bb);
	if(sz[a] < sz[b])
		swap(a, b);
	if(a == b)
		return;
	sz[a] += sz[b];
	pai[b] = a;
	debug("join %d %d %d %d\n", aa, bb, a, b);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		pai[a] = a;
		sz[a] = 1;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		i--;
		j--;
		join(i, j);
	}
	for(int a=0;a<n;a++){
		int r = raiz(a);
		debug("bota no %d %d\n", r, s[a]);
		q[r].insert(-s[a]);
	}
	for(int a=0;a<n;a++){
		int v = -(*q[raiz(a)].begin());
		printf("%d ", v);
		q[raiz(a)].erase(-v);
	}
}
