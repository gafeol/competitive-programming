#include <bits/stdc++.h>
using namespace std;
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

const int MAXN = 212345;
const ll INF = 1e18  + 1ll;

int n, m;
ll k;
int s[MAXN];

ll dp[MAXN];

string ini = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fst = "What are you doing while sending ";
string snd = "? Are you busy? Will you send \""; 
char solve(int n, ll k){
	debug("solve n %d k %lld\n", n, k);
	if(n == 0)
		return ini[k]; 

	if(k < fst.size())
		return fst[k];
	k -= fst.size();
	if(k < dp[n-1])
		return solve(n-1, k);
	k -= dp[n-1]; 
	if(k < snd.size())
		return snd[k];
	k -= snd.size();
	if(k < dp[n-1])
		return solve(n-1, k);
	k -= dp[n-1];
	if(k == 0)
		return '?';
	else
		debug("fodeu %d %lld\n", n, k);
	return '1';
}

int main (){
	dp[0] = 75;
	for(int a=1;a<MAXN;a++){
		if(log(2) + log(dp[a-1]) > 18)
			dp[a] = INF;
		else
			dp[a] = 2ll*dp[a-1] + 64 + 4; 
	}

	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%d%lld", &n, &k);	
		k--;
		if(k >= dp[n]){
			puts(".");
			continue;
		}	
		printf("%c", solve(n, k));
		debug("\n");
	}
}

