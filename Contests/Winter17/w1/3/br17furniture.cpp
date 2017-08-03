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

const int MAXN = 65;

int n, m, k;
int s[MAXN], som[MAXN], sz[MAXN], pos[MAXN], pai[MAXN];
int men[MAXN], mrk[MAXN];

int res;

int raiz(int i){
	if(pai[i] == i) return i;
	return pai[i] = raiz(pai[i]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	
	if(i == j) return ;

	if(sz[i] < sz[j])
		swap(i, j);
	pai[j] = i;
	sz[i] += sz[j];
	men[i] = min(men[i], men[j]);
	som[i] += som[j];
}

void go(int u){
	mrk[u] = 1;
	if(!mrk[pos[u]])
		go(pos[u]);
}

vector<int> ent;

int main (){
	int x;
	while(scanf("%d", &x)!= EOF){
		ent.pb(x);
	}
	n = ent.size()/2;
	int mn = INT_MAX;
	for(int a=0;a<n;a++){
		s[a] = ent[a];
		sz[a] = 1;
		pai[a] = a;
		som[a] = s[a];
		men[a] = s[a];
		mn = min(mn, s[a]);
	}
	for(int a=0;a<n;a++){
		pos[a] = ent[n+a];
		join(a, pos[a]);
	}
	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		int r = raiz(a);
		res += min(men[r]*(sz[r]-2) + som[r], 2*(mn + men[r]) + som[r]-men[r] + mn*(sz[r] - 1));
		go(a);
	}
	printf("%d\n", res);
}
