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
#define div asasfas

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

map<int, int> dp;
vector<int> div;

inline int qtos(int x){
	return x/2 + 1;
}

int go(int x){
	if(dp.find(x) != dp.end())
		return dp[x];
	dp[x] = qtos(x);
	for(int d: div){
		if(d >= x) break;
		if(x%d == 0){
			dp[x] = min(dp[x], qtos((x/d))*go(d));
		}
	}
	return dp[x];
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<sqrt(n)+1;a++){
		if(n%a == 0){
			div.pb(a);
			div.pb(n/a);
		}
	}
	sort(div.begin(), div.end());
	div.erase(unique(div.begin(), div.end()), div.end());
	printf("%d\n", go(n));
}
