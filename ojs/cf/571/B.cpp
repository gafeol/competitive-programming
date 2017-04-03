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

const int MAXN = 312345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

ll dp[10009][5009]

ll go(int i, int cnt, int pos, int ini){
	if(cnt < 0) return INF;
	if(i == n)
		return r = 0;
	if(dp[i][cnt] != -1)
		return dp[i][cnt];
	ll &r = dp[i][cnt];
	r = INF;
	r = min(r, go(i+1, cnt-1, pos, ini));
	pos += k;
	if(pos >= n){
		ini++;
		pos = ini;
		r = min(r, go(i+1, cnt, pos, ini));
	}
	else{
		r = min(r, go(i+1, cnt, pos, ini) - s[i]);
	}

	if(pos == ini)
		return r;
	else
		return r += s[i];
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	sort(s, s+n);
	ll res = 0;
	if(k <= n/2){
		for(int a=0;a<n-1;a++)
			res += s[a+1] - s[a];
	}
	else{
		int cnt = k-1 - (n-k) + 1;
		if(cnt > 0)
			printf("%d\n", go(0, cnt, 0, 0));
	}
}
