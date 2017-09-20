#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> pip;
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

const int MAXN = 512;

int n, m, k, q;
pip s[MAXN*MAXN];

pip mk(ll t, int x, int y){
	return pip(t, pii(x, y));
}

int M[MAXN][MAXN], sum[MAXN][MAXN];

bool go(ll t){
	memset(M, 0, sizeof(M));
	memset(sum, 0, sizeof(sum));
	for(int a=0;a<q;a++){
		if(s[a].fst <= t){
			M[s[a].snd.fst][s[a].snd.snd] = 1;
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			sum[a][b] = sum[a-1][b] + sum[a][b-1] - sum[a-1][b-1] + M[a][b];
		}
	}
	int ok = 0;
	for(int a=k;a<=n;a++){
		for(int b=k;b<=m;b++){
			if(sum[a][b] - sum[a-k][b] - sum[a][b-k] + sum[a-k][b-k] == k*k)
				ok = 1;
		}
	}
	return ok;
}

int main (){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int a=0;a<q;a++){
		int x, y;
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		s[a] = mk(t, x, y);
	}
	sort(s, s+q);
	ll i = 0, j = (ll)2e9;
	while(i < j){
		ll m = (i + j)/2ll;
		if(go(m))
			j = m;
		else
			i = m+1;
	}
	if(i != 2e9)
		printf("%lld\n", i);
	else
		puts("-1");
}

