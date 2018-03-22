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

const int MAXN = 5111;

int n[5], m, k;
int mx;
int s[5][MAXN];
ll dp[MAXN*MAXN];

vector<int> p;

map<int, int> ind;

int main (){
	while(scanf("%d %d %d %d %d", &mx, &n[0], &n[1], &n[2], &n[3]) != EOF && mx + n[0] + n[1] + n[2] + n[3] != 0){
		for(int a=0;a<4;a++){
			for(int i = 0;i < n[a];i++){
				scanf("%d", &s[a][i]);
			}
		}
		ind.clear();
		p.clear();
		for(int a=0;a<n[0];a++){
			for(int b=0;b<n[1];b++){
				p.pb(s[0][a] + s[1][b]);	
				ind[s[0][a] + s[1][b]]++;
			//	debug("add soma %d\n", s[0][a] + s[1][b]);
			}
		}
		sort(p.begin(), p.end());
		p.erase(unique(p.begin(), p.end()), p.end());
		dp[0] = 0;
		for(int i =0;i < p.size();i++){
			if( i != 0) dp[i] = dp[i-1];
			dp[i] += ind[p[i]];
		//	debug("dp[%d] = %lld\n", i, dp[i]); 
		}
		ll res = 0;
		for(int a=0;a<n[2];a++){
			for(int b=0;b<n[3];b++){
				int soma = s[2][a] + s[3][b];
				int cred = mx - soma;
				int i = (upper_bound(p.begin(), p.end(), cred) - p.begin());
				if(i == 0)
					continue;
				res = res + dp[i-1];

			}
		}
		printf("%lld\n", res);
	}
}
