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

int main (){
	for(int a=0;a<4;a++){
		scanf("%lld", &s[a]);
	}
	if(s[0] + s[1] == s[2] + s[3] || s[0] + s[2] == s[1] + s[3] || s[0] + s[3] == s[1] + s[2])
		puts("Yes");
	else
		puts("No");
}
