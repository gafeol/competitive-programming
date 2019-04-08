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

ll fifth(ll x){
	return x*x*x*x*x*x*x;
}

ll sumDigitsFifth(int x){
	ll sum = 0;
	while(x > 0){
		sum += fifth(x%10);
		x /= 10;
	}
	return sum;
}

int main (){
	ll sum = 0;
	for(ll val = 1;val<=3000000000LL;val++){
		if(val == sumDigitsFifth(val)){
			printf("%lld\n", val);
			sum += val;
		}
	}
	printf("SOMA %lld\n", sum);
}

