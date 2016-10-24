

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 5123;
const ll INF = LLONG_MAX - 1e8;

int n, m, k, b;
ll d[MAXN], d2[MAXN], s[MAXN], sum[MAXN];

vector<pil> adj[MAXN], inv[MAXN];

set<pli> q;

int opt[MAXN][MAXN];

ll dp[MAXN][MAXN];

ll cus(int i, int j){
	//de i+1 a j
	return (j-i-1)*(sum[j] - sum[i]);
}

void solve(int i, int j, int l, int r, int kk){
	if(i > j)
		return;
	int m = (i + j)/2;
	for(int a=l;a<=min(m-1,r);a++){
		dp[m][kk] = min(dp[a][kk-1] + cus(a, m), dp[m][kk]);
		if(dp[m][kk] == dp[a][kk-1] + cus(a, m))
			opt[m][kk] = a;
	}

	solve(i, m-1, l, opt[m][kk], kk);
	solve(m+1, j, opt[m][kk], r, kk);
}

int main (){
	scanf("%d%d%d%d", &n, &b, &k, &m);
	for(int a=0;a<=n;a++){
		d[a] = INF;
		d2[a] = INF;
		for(int bb=0;bb<=k;bb++){
			dp[a][bb] = INF;
		}
	}
	for(int a=1;a<=m;a++){
		int i, j;
		ll c;
		scanf("%d%d%lld", &i, &j, &c);
		inv[i].pb(pil(j, c));
		adj[j].pb(pil(i, c));
	}
	q.insert(pii(0ll, b+1));
	d[b+1] = 0;
	while(!q.empty()){
		int v = q.begin()->snd;
		q.erase(q.begin());
		for(pil nxt: adj[v]){
			int u = nxt.fst;
			ll cus = nxt.snd;
			if(d[u] > d[v] + cus){
				if(d[u] != INF)
					q.erase(pli(d[u], u));
				d[u] = d[v] + cus;
				q.insert(pli(d[u], u));
			}
		}
	}


	q.insert(pli(0ll, b+1));
	d2[b+1] = 0;
	while(!q.empty()){
		int v = q.begin()->snd;
		q.erase(q.begin());
		for(pil nxt: inv[v]){
			int u = nxt.fst;
			ll cus = nxt.snd;
			if(d2[u] > d2[v] + cus){
				if(d2[u] != INF)
					q.erase(pli(d2[u], u));
				d2[u] = d2[v] + cus;
				q.insert(pli(d2[u], u));
			}
		}
	}
	for(int a=1;a<=b;a++){
		s[a] = d[a] + d2[a];
		sum[a] = sum[a-1] + s[a];
	}
	sort(s, s+b);
	k--;
	for(int a=1;a<=b;a++){
		dp[a][0] = cus(0, a);
		//	printf("dp[%d][%d] %lld\n", a, 0, dp[a][0]);
	}
	for(int kk = 1;kk <= k;kk++){
		solve(1, b, 1, b, kk);
	}
	printf("%lld", dp[b][k]);
}
