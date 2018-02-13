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

int n, m, k, d;
ll s[MAXN][2];

int main (){
	scanf("%d%d%d", &n, &k, &d);
	s[0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			s[i+j][(j >= d)] = mod(s[i+j][(j>=d)] + s[i][0]);
			s[i+j][1] = mod(s[i+j][1] + s[i][1]);
		}
	}
	printf("%lld\n", s[n][1]);
}

