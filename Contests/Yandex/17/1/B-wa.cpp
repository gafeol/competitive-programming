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

ll n, m, k;
int s[MAXN];

inline ll go(ll x){
	return (((x%500) + 500)%500); 
}

int main (){
	ll res =0;
	scanf("%lld %lld", &n, &k);
	if(k%500 != 0){
		res = 500 + go(-n);	
		printf("%lld\n", res);
		return 0;
	}
	if(k*2ll == n){
		res = go(-n);
		printf("%lld\n", res);
	}
	else{
		k++;
		res = 500 + go(-n);
		printf("%lld\n", res);
	}
}
