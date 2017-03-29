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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

int pai[MAXN], sz[MAXN];
int ar[MAXN];
int cmp;

ll ans;

vector<int> adj[MAXN];

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return ;
	cmp--;
	if(sz[j] > sz[i])
		swap(i, j);
	
	sz[i] += sz[j];
	pai[j] = i;
}

int main (){
	scanf("%d%d", &n, &m);
	cmp = m;
	for(int a=0;a<m;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	memset(ar, -1, sizeof(ar));
	ll cnt = 0;
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		if(ar[i]+1)
			join(ar[i], a);
		if(ar[j]+1)
			join(ar[j], a);
		ar[i] = a;
		ar[j] = a;
		if(i == j){
			cnt++;
			continue;
		}
		adj[i].pb(j);
		adj[j].pb(i);
	}
	if(m == 1){
		puts("0");
		return 0;
	}
	if(cmp > 1){
		puts("0");
		return 0;
	}
	ans = 0;
	for(int a=1;a<=n;a++){
		ll tam = (ll)adj[a].size();
		ans += (tam*(tam-1))/2ll;
	}
	ans += (cnt*(cnt-1))/2ll + (m-cnt)*cnt;
	printf("%lld\n", ans);
}
