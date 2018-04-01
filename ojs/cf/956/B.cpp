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

int n,m;
ll k;
ll s[MAXN];

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	int j = 0;
	double ans = -1;
	for(int i=0;i<n;i++){
		while(j+1 < n && s[j+1] - s[i] <= k)
			j++;
		if(j > i+1){
			ans = max(ans, ((double)s[j] - s[i+1])/(s[j] - s[i]));
		}
	}
	if(ans < 0)
		puts("-1");
	else
		printf("%.15f\n", ans);
}

