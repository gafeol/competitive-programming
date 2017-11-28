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

const int MAXN = 2123;

const ll INF = (ll)2e9;

int n, m, k;
ll s[MAXN];

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll res[MAXN];

int main (){
	scanf("%d", &n);
	int nt = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		nt += (s[a] != 1);
	}
	int res = INF;
	for(int i=0;i<n;i++){
		ll val = s[i];
		for(int j=i;j<n;j++){
			val = gcd(val, s[j]);
			if(val == 1){
				res = min(res, (j - i) + nt - (s[j] != 1));
				break;
			}
		}
	}
	if(res == INF)
		puts("-1");
	else
		printf("%d\n", res);
}

