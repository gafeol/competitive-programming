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

const int MAXN = 212345, MASK = (1<<11) + 10;

int n, m, k;
int s[MAXN];

ll dp[11][67][MASK][2];

ll b, mai;

ll go(int i, int bm, int lo){
	if(dp[i][bm][lo] == -1) return dp[i][bm][lo];	

}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r); 
		mai = r;
		go(0, mai);
		printf("%lld\n", go(0, ) - go(r));
	}
}
