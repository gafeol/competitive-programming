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

int m, k;

ll n, s[MAXN];

int main (){
	scanf("%lld%d", &n, &m);
	ll mn = LLONG_MAX;
	int imn;
	for(int a=0;a<m;a++){
		scanf("%lld", s+a);	
		if(n%s[a] < mn){
			mn = n%s[a];
			imn = a;
		}
	}
	printf("%d %lld\n", imn+1, n/s[imn]); 

}

