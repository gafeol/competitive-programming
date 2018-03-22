#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
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
vector<pip> v;

int pai[MAXN], sz[MAXN];

pip mk(int a, int b, int c){
	return pip(a, pii(b, c));
}

int raiz(int i){
	if(pai[i] == i) return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(sz[i] > sz[j])
		swap(i, j);
	pai[i] = j;
	sz[j] += sz[i];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	for(int a=0;a<m;a++){
		int i, j, c;	
		scanf("%d%d%d", &i, &j, &c);
		v.pb(mk(c, i, j));
	}
	sort(v.begin(), v.end());
	int res = 0;
	for(int a=0;a<m;a++){
		int i = v[a].snd.fst;
		int j = v[a].snd.snd;
		int c = v[a].fst;
		if(raiz(i) != raiz(j)){
			join(i, j);
			res += c;
		}
	}
	printf("%d\n", res);
}

