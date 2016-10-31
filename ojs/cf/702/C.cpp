#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }


#define int ll
const int MAXN = 212345;

int n, m, k;
int s[MAXN];
int r[MAXN];
int aft[MAXN], bef[MAXN];

main (){
	scanf("%lld%lld", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
	}
	for(int a=1;a<=m;a++){
		scanf("%lld", &r[a]);
	}
	r[0] = bef[0] = LLONG_MIN + 1e9 + 10;
	r[m+1] = aft[n] = LLONG_MAX;
	int i = 1;
	int j = 0;
	while(i <= n){
		while(r[j+1] <= s[i])
			j++;
		bef[i] = s[i] - r[j];
		i++;
	}
	i = n;
	j = m+1;
	while(i > 0){
		while(r[j-1] >= s[i])
			j--;
		aft[i] = r[j] - s[i];
		i--;	
	}
	int res = 0;
	for(int a=1;a<=n;a++){
		res = max(res, min(aft[a], bef[a]));
	}
	printf("%lld\n", res);
}
