#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

int n, m;
int s[MAXN], mrk[MAXN];
vector<pil> adj[MAXN];
map<int, pii> s;
map<int, int> cnt;
int deg;

void add(int v){
	cnt = 62;
	while(cnt > 0){
		
		v <<= 1;
		cnt--;
	}
}

void go(int u, ll x){
	add(x);
	mrk[u] = 1;
	for(pii nxt: adj[u]){
		go(nxt.fst, x^nxt.snd); 
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int i, j;
		ll k;
		scanf("%d%d%lld", &i, &j, &k);
		adj[i].pb(pii(j, k));
		adj[j].pb(pii(i, k));
	}
	for(int a=1;a<=n;a++){
		if(mrk[a]) continue;
		s.clear();
		s[0].fst = -1;
		s[0].snd = -1;
		deg = 0;
		go(a);
	}
}
