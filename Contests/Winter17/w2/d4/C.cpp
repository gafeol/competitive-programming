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

int n, k;
int s[MAXN];
int mrk[MAXN];
ll res;

ll inv5;
int M[MAXN][MAXN];
ll eq[MAXN][MAXN];

vector<int> adj[MAXN];

ll ch(ll i, ll j){
	if(j > i) return 0;
	if(j == 0) return 1;
	if(j == 1) return mod(i);
	if(j == 2) return mod((i*(i-1))/2ll);
	if(j == 3) return mod((i*(i-1ll)*(i-2ll))/6ll);
	if(j == 4) return mod((i*(i-1ll)*(i-2ll)*(i-3ll))/(4*3*2));
	return mod(mod(i*(i-1ll)*(i-2ll))*mod(mod((i-3ll)*(i-4ll))*inv5));
}

void go(int u){
	mrk[u] = 1;
	ll i = adj[u].size();
	i--;
	ll j;
	for(int nxt: adj[u]){
		j = adj[nxt].size();
		j--;
		ll MI = eq[u][nxt];
		ll U = i - eq[u][nxt];
		ll D = j - eq[u][nxt];
		for(int up=0;up<=3;up++){
			for(int dw=0;dw<=2;dw++){
				ll mu = 3 - up;
				ll md = 2 - dw;
				res = mod(res + mod(mod(ch(U, up)*ch(MI, mu))*mod(ch(D, dw)*ch(MI - mu, md))));
			}
		}
		if(mrk[nxt]) continue;
		go(nxt);
	}
}

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2);
	ans = mod(ans*ans);
	if(e&1)
		ans = mod(base*ans);
	return ans;
}

int main (){
	int m;
	scanf("%d%d", &n, &m);
	inv5 = expo(5*4*3*2, modn-2);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		M[i][j] = 1;
		M[j][i] = 1;
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(!M[a][b]) continue;
			for(int c=1;c<=n;c++){
				eq[a][b] += (M[a][c] == M[b][c] && M[a][c] == 1);
			}
		}
	}
	for(int u=1;u<=n;u++){
		if(!mrk[u])
			go(u);
	}
	printf("%lld\n", res);
}
