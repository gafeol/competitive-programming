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
ll A, B;
int s[MAXN];

int main (){
	scanf("%lld%lld%d", &A, &B, &n);
	for(int a=0;a<n;a++){
		ll l, t, m;
		scanf("%lld %lld %lld", &l, &t, &m);
		ll h = A + B*(l-1);
		if(h > t){
			puts("-1");
			continue;
		}
		ll sum = h;
		ll i = l, j = l + 2000;
		while(i < j){
			ll mid = (i + j + 1)/2ll;
			ll h = A + B*(mid-1);
			ll sum = ((h + A+B*(l-1))*(mid - l + 1))/2ll;
			//debug("m %lld sum %lld h %lld\n", mid, sum, h);
			if(h > t || sum > t*m){
				j = mid - 1;
			}
			else{ 
				i = mid;
			}
		}
		printf("%lld\n", i);

	}
}

