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

const int MAXN = 212345;

int s[2][MAXN];
int n[3];

int dp[3][MAXN];

int main (){
	scanf("%d%d", n, n+1);
	ll mx[2], sum[2];
	mx[0] = mx[1] = 0;
	sum[0] = sum[1] = 0;
	for(int t=0;t<2;t++){
		for(int a=0;a<n[t];a++){
			scanf("%d", &s[t][a]);
			mx[t] = max(mx[t], (ll)s[t][a]);
			sum[t] += s[t][a];
		}
	}
	int ini = INT_MAX;
	int fim = INT_MIN;
	for(int a=0;a<n[0];a++){
		if(s[0][a] == mx[0]){
			ini = min(ini, a);
			fim = max(fim, a);
		}
	}
	ll dez = 1e9;
	ll res = sum[0]*dez + mx[0]*(n[1]-1)*dez;
	res += sum[1] + s[1][0]*ini + s[1][n[1]-1]*(n[0] - fim - 1);
	res += mx[1]*(fim - ini);
	printf("%lld\n", res);
}

