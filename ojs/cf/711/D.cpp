#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { 
	if(x < 0){ 
		return x + modn;
	} 
	else{ 
		return x % modn;
	} 
}

const int MAXN = 212345;

int n, p[MAXN], mrk[MAXN];
ll cnt[MAXN];

int deg;

ll ans, pot[MAXN];

vector <int> adj[MAXN];

void pega(int i, int f){
//	printf("pega %d %d\n", i, f);
	deg++;
	while(i != f){
		mrk[i] = deg;
		cnt[deg]++;
		i = p[i];
	}
	mrk[i] = deg;
	cnt[deg]++;
}

void go(int v){
	mrk[v] = 1;
	int paiz = 0;
	for(int nxt : adj[v]){
		if(nxt == p[v]){
			paiz++;
			if(paiz == 2)
				pega(v, nxt);
			continue;
		}
		if(mrk[nxt]){
			if(mrk[nxt] == 1)
				pega(v, nxt);
		}
		else{
			p[nxt] = v;
			go(nxt);
		}
	}
}

int main (){
	pot[0] = 1;
	deg = 1;
	scanf("%d", &n);
	for(int a=1;a<=n+1;a++){
		pot[a] = mod(pot[a-1] + pot[a-1]);
	}
	for(int a=1;a<=n;a++){
		int j;
		scanf("%d", &j);
		adj[a].pb(j);
		adj[j].pb(a);
	}
	for(int a=1;a<=n;a++){
		if(!mrk[a]){
			p[a] = 0;
			go(a);
		}
	}
	ll sob = n;
	ans = pot[n];
	ll cor = 1;
	//printf("%lld\n", ans);
	for(int a=2;a<=deg;a++){
		sob -= cnt[a];
		ans = mod(ans - mod(cor*pot[sob+1]));
	//	printf("%lld\n", ans);
		cor = mod(cor * mod((pot[cnt[a]] - 2)));
	}
	printf("%lld\n", ans);
}
