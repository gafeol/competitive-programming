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
ll s[MAXN];

ll sum;
int mrk[MAXN];

int loop(int i){
	if(i == n+1)
		return 1;
	if(i == 0)
		return n;
	return i;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
		sum += s[a];
	}
	ll sumc = 0;
	for(int a=0;a<m;a++){
		int v;
		scanf("%d", &v);
		mrk[v] = 1;
		sumc += s[v];
	}
	ll ans = 0;
	for(int a=1;a<=n;a++){
		if(mrk[a]){
			ans += (sum -s[a])*s[a];
		}
		else{
			ans += s[a]*sumc;
			if(!mrk[loop(a-1)])
				ans += s[a]*s[loop(a-1)];
			if(!mrk[loop(a+1)])
				ans += s[a]*s[loop(a+1)];
		}
	}
	printf("%lld", ans/2ll);
}
