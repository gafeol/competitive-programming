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

const int MAXN = 612345;

int n, m;
ll k;
char s[MAXN];

int main (){
	scanf("%d%lld", &n, &k);
	ll ans = 0;
	int h = 0;
	int deg = 0;
	while(ans + h <= k && n > 0){
		s[deg++] = '(';
		ans += h;
		h++;
		n--;
	}
	while(h > 0){
		if(n == 0 && ans != k) break;
		while(n > 0 && ans + h <= k){
			s[deg++] = '(';
			s[deg++] = ')';
			ans += h;
			n--;
		}
		s[deg++] = ')';
		h--;
	}
	while(n > 0){
		s[deg++] = '(';
		s[deg++] = ')';
		n--;
	}
	if(ans == k)
		for(int a=0;a<deg;a++)
			printf("%c", s[a]);
	else
		puts("Impossible");
}

