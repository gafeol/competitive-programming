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

const int MAXN = 40034;

ll n, m, k;
int s[MAXN];
int mrk[MAXN];

vector<ll> pri;

int main (){
	for(ll a=2;a<MAXN;a++){
		if(mrk[a]) continue;
		pri.pb(a);
		for(ll b = a;a * b < MAXN;b++)
			mrk[a*b] = 1;
	}
	scanf("%lld", &n);
	if(n == 1){
		puts("no");
		return 0;
	}
	for(ll p: pri){
		if(n % p == 0){
			while(n%p == 0)
				n/=p;
			if(n != 1)
				puts("no");
			else
				puts("yes");
			return 0;
		}
	}
	puts("yes");

}

