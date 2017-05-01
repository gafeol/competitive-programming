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
int s[MAXN], l[MAXN], r[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", s+a);
	}
	l[0] = 0x3f3f3f3f;
	r[n+1] = 0x3f3f3f3f;
	for(int a=1;a<=n;a++){
		l[a] = l[a-1]+1;
		if(s[a] ==  0)
			l[a] =  0;
	}
	for(int a=n;a>0;a--){
		r[a] = r[a+1]+1;
		if(s[a] ==  0)
			r[a] =  0;
	}
	for(int a=1;a<=n;a++){
		printf("%d ", min(l[a], r[a]));
	}
}
