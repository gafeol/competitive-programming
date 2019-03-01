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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

ll expo(ll base, ll e){
	if(e == 0)
		return 1;

	ll ans = expo(base, e/2ll);
	ans = mod(ans*ans);

	if((e&1))
		ans = mod(ans*base); 
	
	return ans;
}

ll inv(ll x){
	return expo(x, modn-2);
}

int pos[MAXN];

ll pont[MAXN];

int main (){
	scanf("%d", &n);
	ll cnt = 0;
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
		if(s[a] == -1)
			cnt++;
		else
			pos[s[a]] = a;
	}

	ll foi = 0;
	for(int a=1;a<=n;a++){
		if(s[a] == -1){
			foi++;
			continue;
		}
		pont[s[a]] = cnt - foi;
	}

	ll res = 0;
	
	
	res = mod(res * inv(cnt));
	printf("%lld\n", res);
}

