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
char s[MAXN];

int main (){
	scanf(" %s", s);
	n = strlen(s);
	ll res = 0;
	for(ll a=0;a<(1<<(n-1));a++){
		int pos[20];
		memset(pos, 0, sizeof(pos));
		for(ll i=0;i<n;i++){
			if(a&(1ll<<i)){
				pos[i] = 1;
			}
		}
		ll cur = 0;
		for(int i=0;i<n;i++){
			cur *= 10ll;
			cur += s[i]- '0';
			if(pos[i]){
				res += cur;
				cur = 0;
			}
		}
		res += cur;
	}
	printf("%lld\n", res);
}

