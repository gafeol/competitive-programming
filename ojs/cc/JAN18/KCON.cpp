
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

const int MAXN = 312345;

int n, m, k;
ll s[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &k);
		ll som  = 0;
		for(int a=0;a<n;a++){
			scanf("%lld", s+a);
			som += s[a];
		}
		if(k > 1){
			int mid = 0;
			if(som > 0){
				mid = 1;
				s[n] = som*(k-2ll);	
			}
			for(int a=n+mid;a<2*n+mid;a++){
				s[a] = s[a-n-mid];
			}
			n = n*2 + mid;
		}
		ll res = s[0];
		ll best = 0;
		for(int a=0;a<n;a++){
			best += s[a];
			res = max(res, best);
			if(best < 0)
				best = 0;
		}
		printf("%lld\n", res);
	}
}

