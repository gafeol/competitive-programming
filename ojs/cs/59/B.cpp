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

int n, m, k;
ll w[2], p[2];

int main (){
	for(int a=0;a<2;a++){
		scanf("%lld %lld", &w[a], &p[a]);
	}
	ll bef, aft, win, lo;
	for(ll a=0;a<=w[0];a++){
		if((100*a)/w[0] == p[0]){
			win = a;
			break;
		}
	}
	bef = win;
	for(ll a = win;a <= w[1];a++){
		if((100*a)/w[1] == p[1] && a - bef <= w[1] - w[0])
			aft = a;		
	}
	assert(aft >= bef);
	printf("%lld\n", aft-bef);
}

