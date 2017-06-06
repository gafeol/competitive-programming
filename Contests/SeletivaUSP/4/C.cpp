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

const int MAXN = 202;
ll INF = 4000000000000ll;

int n, m, k;
int ini, fim;
ll d;
ll s[MAXN];
int L[MAXN], R[MAXN];
ll dp[MAXN][2*MAXN*MAXN + MAXN];
int tempo;
int atu[MAXN][2*MAXN*MAXN + MAXN];

vector<ll> pos;

map<ll, int> ind; 

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

int main (){
	for_tests(t, tt){
		++tempo;
		pos.clear();
		ind.clear();
		scanf("%d %lld", &n, &d);
		ll mx = -1, mn = INF;
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			mn = min(mn, s[a]);
			mx = max(mx, s[a]);
			if(ind.find(s[a]) == ind.end()){
				ind[s[a]] = 1;
				pos.pb(s[a]);
			}

		}
		for(int a=0;a<n;a++){
			for(ll k=1;k<=n;k++){
				if(s[a] + d*k < mx && ind.find(s[a] + d*k) == ind.end()){
					ind[s[a] + d*k] = 1;
					pos.pb(s[a] + d*k);
				}
				if(s[a] - d*k > mn && ind.find(s[a] - d*k) == ind.end()){
					ind[s[a] - d*k] = 1;
					pos.pb(s[a] - d*k);
				}
			}
		}
		//debug("sz %d\n", (int)pos.size());
		sort(pos.begin(), pos.end());
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
		if(go(0, ini) >= INF)
			puts("impossible");
		else
			printf("%lld\n", go(0, ini));
	}
}
