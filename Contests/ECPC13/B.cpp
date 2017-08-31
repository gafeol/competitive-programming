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

struct ar{
	int i, j, c;
	ar(int ii, int jj, int cc){
		i = ii;
		j = jj;
		c = cc;
	}
	ar(){}
} ares[MAXN];


vector<int> mst;

bool cmp(ar a, ar b){
	return (a.c < b.c);
}

int pai[MAXN], sz[MAXN];

int raiz(int i){
	if(pai[i] == i) return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);

}

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &m);
		for(int a=1;a<=n;a++){
			pai[a] = a;
			sz[a] = 0;
		}
		for(int a=0;a<m;a++){
			int i, j, c;
			scanf("%d %d %d", &i, &j, &c);	
			ares[a] = ar(i, j, c);
		}
		sort(ares, ares+m, cmp);
		for(int a=0;a<m;a++){
			int i = ares[a].i;
			int j = ares[a].j;
			if(raiz(i) == raiz(j)) continue;
			mst.pb(ares[a]);
			join(i, j);
		}
	}
}

