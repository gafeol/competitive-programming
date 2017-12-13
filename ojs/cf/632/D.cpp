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

const int MAXN = 2123456, INF = 0x3f3f3f3f;

int n, m, k;
int mrk[MAXN];
ll s[MAXN];

ll dp[MAXN], cnt[MAXN];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		if(s[a] < MAXN)
			cnt[s[a]]++;
	}
	for(int p=1;p<MAXN;p++){
		for(ll i=1;i*p <= m;i++){
			dp[i*p] += cnt[p];	
		}
	}
	int mx = -1, imx;
	for(int a=1;a<=m;a++){
		if(dp[a] > mx){
			mx = dp[a];
			imx = a;
		}
	}
	printf("%d %d\n", imx, mx);
	for(int a=0;a<n;a++){
		if(imx%s[a] == 0)
			printf("%d ", a+1);
	}
}

