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

ll  x, S;
ll ans;
int s[MAXN];

int main (){
	ans = 1;
	int cnt = 0;
	scanf("%lld %lld", &S, &x);
	ll sum = S;
	int bo = 0;
	for(ll i = 41;i>=0;i--){
		if((1ll<<i)&x){
			sum -= (1ll<<i);
			s[i] = 1;
			ans *= 2ll;
			cnt++;
		}
		else{
			if(sum >= (1ll<<(i+1))){
				sum -= (1ll<<(i+1));
				s[i] = 2;
				bo = 1;
			}
		}
	}
	if(sum < 0 || sum > 0){
		puts("0");
		return 0;
	}
	if(bo)
		printf("%lld\n", ans);
	else
		printf("%lld\n", ans - 2);
}

