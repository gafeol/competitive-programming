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
int l, r;
int s[MAXN];
int dp[MAXN];

vector<int> v[2];

bool cmp(int a, int b){
	return (b < a);
}

int in(int x){
	return (x >= l && x<= r);
}

int main (){
	scanf("%d%d%d", &n, &l, &r);
	memset(dp, -1, sizeof(dp));
	int sum = 0;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		sum += s[a];
	}
	int auxl = l, auxr = r;
	l = sum - auxr;
	l = max(l, 0);
	r = sum - auxl;
	r = max(r, 0);
	r = min(r, sum);
	dp[0] = 0;
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		v[t].pb(s[a]);
	}
	for(int x: v[0]){
		for(int a=sum-x;a>=0;a--){
		if(dp[a] == -1) continue;
			dp[a+x] = 0;
		}
	}
	sort(v[1].begin(), v[1].end(), cmp);
	for(int x: v[1]){
		for(int a=sum-x;a>=0;a--){
			if(dp[a] == -1) continue;
			dp[a+x] = max(dp[a+x], dp[a] + in(a+x));
		}
	}
	printf("%d\n", *max_element(dp, dp+sum+1));
}


