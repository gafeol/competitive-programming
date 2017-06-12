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

vector<ll> pos;

inline ll go(int i, int p){
	if(i + 1 == n-1){
		if(L[p] <= fim && R[p] >= fim)
			return 0;
		return INF;
	}
	else
		assert(0);
}

multiset<ll> best;

int main (){
	for_tests(t, tt){
		scanf("%d %lld", &n, &d);
		ll mx = LLONG_MIN, mn = LLONG_MAX;
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			mx = max(mx, s[a]);
			mn = min(mn, s[a]);
			pos.pb(s[a]);

		}
		for(int a=0;a<n;a++){
			for(ll k=1;k<=a+1;k++){
				if(s[a] + d*k < mx)
					pos.pb(s[a] + d*k);
				if(s[a] - d*k > mn)
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
		

		for(int p=0;p<pos.size();p++){
			dp[n-2][p] = go(n-2, p);
		}

		for(int i = n-3;i >= 0;i--){
			int l = 0, r = 0;
			for(int p=0;p<pos.size();p++){
				while(r <= R[p]){
					best.insert(abs(s[i+1] - pos[r]) + dp[i+1][r]);
					r++;
				}
				while(l < L[p]){
					best.erase(best.find(abs(s[i+1] - pos[l]) + dp[i+1][l]));
					l++;
				}
				dp[i][p] = *best.begin();
			}
			best.clear();
		}
		if(dp[0][ini] >= INF)
			puts("impossible");
		else
			printf("%lld\n", dp[0][ini]);
		pos.clear();
	}
}
