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

int main (){
	scanf("%d%d", &m, &n);
	for(int a=0;a<n;a++){
		puts("1");
		fflush(stdout);
		int ans;
		scanf("%d", &s[a]);
		if(s[a] == 0) return 0;
	}
	int a = 0;
	ll i = 1, j = m;
	while(1){
		ll mid = (i + j)/2ll;
		printf("%lld\n", mid);
		fflush(stdout);
		int ans;
		scanf("%d", &ans);
		if(ans == 0) return 0;
		ans = ans*s[a];
		if(ans == -1)
			j = mid-1;
		else
			i = mid+1;
		a = (a+1)%n;
	}
}

