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

const int MAXN = 102, MAXM = 2*MAXN*MAXN + MAXN;
ll INF = 4000000000000ll;

int n, m, k;
int ini, fim;
ll d;
ll s[MAXN];
int L[MAXM], R[MAXM];
ll dp[MAXN][MAXM];
int opt[MAXN][MAXM];
int tempo;
int atu[MAXN][MAXM];

vector<ll> pos;

ll go(int i, int p){
//	debug("go(%d %d) pos[] %lld\n", i, p, pos[p]);
	if(atu[i][p] != tempo){
		atu[i][p] = tempo;
		dp[i][p] = -1;
	}
	if(dp[i][p] != -1)
		return dp[i][p];

	if(i + 1 == n-1){
		if(L[p] <= fim && R[p] >= fim)
			return 0;
		return INF;
	}

	dp[i][p] = INF;
	for(int a=L[p];a<=R[p];a++){
		dp[i][p] = min(dp[i][p], go(i+1, a) + abs(s[i+1] - pos[a]));
	}

	return dp[i][p];
}

void calculaopt(int i, int pl, int pr, int ole, int ori){
//	debug("calculaopt(%d, %d, %d, %d, %d)\n", i, pl, pr, ole, ori);
	if(pl > pr) return ;

	int m = (pl + pr)/2;

	if(atu[i][m] != tempo){
		atu[i][m] = tempo;
		dp[i][m] = INF;
	}

	for(int a=max(L[m], ole);a <= min(R[m], ori);a++){
//		debug("testa a %d pod[a] %lld\n", a,  pos[a]);
		if(dp[i][m] >= go(i + 1, a) + abs(s[i+1] - pos[a])){
//			debug("opt[%d][%d] %d\n", i, m, a);
			dp[i][m] = go(i + 1, a) + abs(s[i+1] - pos[a]);
			opt[i][m] = a;
		}
	}

	calculaopt(i, pl, m-1, ole, opt[i][m]);
	calculaopt(i, m+1, pr, opt[i][m], ori);
}

int main (){
	for_tests(t, tt){
		++tempo;
		pos.clear();
		scanf("%d %lld", &n, &d);
		ll mx = -1, mn = INF;
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			mn = min(mn, s[a]);
			mx = max(mx, s[a]);
			pos.pb(s[a]);

		}
		for(int a=0;a<n;a++){
			for(ll k=1;k<=n;k++){
				pos.pb(s[a] + d*k);
				pos.pb(s[a] - d*k);
			}
		}
		//debug("sz %d\n", (int)pos.size());
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		//debug("sz %d\n", (int)pos.size());
		int l = 0;
		for(int i=0;i<pos.size();i++){
			while(l < i && pos[l] < pos[i] - d)
				l++;
			L[i] = l;
		}

		int r = pos.size()-1;
		for(int i=pos.size()-1;i>=0;i--){
			while(r > i && pos[r] > pos[i] + d)
				r--;
			R[i] = r;
		}

		for(int i=0;i<pos.size();i++){
			if(pos[i] == s[0])
				ini = i;
			if(pos[i] == s[n-1])
				fim = i;
		}
		for(int i=n-3;i>=0;i--){
			calculaopt(i, 0, pos.size()-1, 0, pos.size()-1);
		}
		if(go(0, ini) >= INF)
			puts("impossible");
		else
			printf("%lld\n", go(0, ini));
	}
}
