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

ll x;

int main (){
	int res = 0;
	scanf("%d%lld", &n, &x);
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c %lld", &c, &s[a]);
		if(c == '-'){
			if(x >= s[a])
				x -=s[a];
			else
				res++;
		}
		else{
			x += s[a];
		}
	}
	printf("%lld %d\n", x, res);
}
