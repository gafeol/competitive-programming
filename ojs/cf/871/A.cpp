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

int n, m, k;
int s[MAXN];

int mx(int x){
	int res = 0;
	if(x%4 == 0)
		return x/4;
	if((x-9)%4 == 0) // 1
		return 1 + (x-9)/4;
	if((x-6)%4 == 0) // 2
		return 1 + (x-6)/4;
	return 2 + (x-15)/4; // 3 
}

vector<int> c;

int dp[2000];

int main (){
	scanf("%d", &n);
	for(int a=4;a<=1000;a++){
		int np = 0;
		for(int b=2;b<a;b++)
			if(a%b == 0)
				np = 1;
		if(np){
			c.pb(a);
		}

	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int a=0;a<=1000;a++){
		if(dp[a] == -1) continue;
		for(int x: c){
			if(a + x < 1001)
				dp[a+x] = max(dp[a+x], dp[a]+1);
		}
	}
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		if(x <= 1000)
			printf("%d\n", dp[x]);
		else{
			printf("%d\n", mx(x));
		}
	}
}

