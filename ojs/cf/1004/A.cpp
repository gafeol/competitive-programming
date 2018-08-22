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
ll s[MAXN];

map<ll, int> mrk;

int main (){
	ll d;
	scanf("%d%lld", &n, &d);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	int res= 0;
	for(int a=0;a<n;a++){
		ll p = s[a] - d;
		if(mrk[p] == 0){
			mrk[p] = 1;
			ll mn = d;
			if(a > 0)
				mn = min(mn, abs(s[a-1] - p));
			if(mn == d)
				res++;
		}
		p = s[a] + d;
		if(mrk[p] == 0){
			mrk[p] = 1;
			ll mn = d;
			if(a+1 < n)
				mn= min(mn, abs(s[a+1] - p));
			if(mn == d)
				res++;
		}
	}
	printf("%d\n",res);
}

