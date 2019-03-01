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
char s[MAXN];

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	ll res = 1;
	
	ll cnti = 1;
	for(int a=1;a<n;a++){
		if(s[a] != s[0])
			break;
		cnti++;
	}
	res += cnti;

	
	
	ll cntf = 1;
	for(int a=n-2;a>=0;a--){
		if(s[a] != s[n-1])
			break;
		cntf++;
	}
	res += cntf;
	
	res = mod(res);

	if(s[0] == s[n-1]){
		res = mod(res + cnti*cntf);

	}

	printf("%lld\n", res);
}

