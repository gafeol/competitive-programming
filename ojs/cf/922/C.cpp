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

const int MAXN = 2123456;

ll n, m, k;
int s[MAXN];

map<ll, ll> ind;


int main (){
	scanf("%lld%lld", &n, &k);
	if(k == 1){
		puts("Yes");
		return 0;
	}
	if(n == 1){
		if(k > 2)
			puts("No");
		else
			puts("Yes");
		return 0;
	}
	if(k >= n){
		puts("No");
		return 0;
	}
	for(int i=1;i<min(k+1, 5000000ll);i++){
		if(ind.find((n%i)) != ind.end()){
			printf("No");
			return 0;
		}
		ind[(n%i)] = i;
	}
	puts("Yes");
}

