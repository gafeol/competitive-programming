#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 5001;

int n, m, k;
ll T;
int s[MAXN], deg[MAXN];

ll dp[MAXN][MAXN];

vector<pii> adj[MAXN];
vector<pii> inv[MAXN];

queue <int> q;

int main (){
	scanf("%d%d%lld", &n, &m, &T);
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			dp[a][b] = 1e13;
		}
	}
	for(int a=0;a<m;a++){
		int i, j;
		ll t;
		scanf("%d%d%lld", &i, &j, &t);
		adj[j].pb(pii(i, t));
		inv[i].pb(pii(j, t));
		deg[i]++;
	}
	dp[n][1] = 0;
	for(int a=1;a<=n;a++){
		if(!deg[a])
			q.push(a);
	}
	int cnt = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(pii nxt: adj[u]){
			int v = nxt.fst;
			ll c = nxt.snd;
			deg[v]--;
			if(deg[v] == 0)
				q.push(v);
			for(int a=1;a<=cnt;a++){
				dp[v][a+1] = min(dp[u][a] + c, dp[v][a+1]);
			}
		}
		cnt++;
	}
	ll ans = LLONG_MIN;
	for(int a=0;a<=n;a++){
		if(dp[1][a] <= T)
			ans = a;
	}
	printf("%lld\n", ans);
	int u = 1;
	while(u != n){
		printf("%d ", u);
		for(pii nxt: inv[u]){
			int v = nxt.fst;
			ll c = nxt.snd;
			if(dp[u][ans] == dp[v][ans-1] + c){
				u = v;
				break;
			}
		}
		ans--;
	}
	printf("%d\n", u);
}
