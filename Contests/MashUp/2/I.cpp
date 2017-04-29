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

multiset<ll> ast;

int main (){
	scanf("%d", &n);
	ll sum = 0;
	int res = 0;
	for(int a=0;a<n;a++){
		ll t, dmg;
		scanf("%lld%lld", &t, &dmg);
		sum += dmg;
		ast.insert(dmg);
		while(t - sum < 0){
			res++;
			sum -= *(ast.rbegin());
			ast.erase(ast.find(*(ast.rbegin())));
		}
	}
	printf("%d\n", res);
}
