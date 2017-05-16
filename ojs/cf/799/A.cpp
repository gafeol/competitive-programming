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

#define div sdasda

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

inline int div(int a, int b){
	if(a%b == 0)
		return a/b;
	return a/b + 1;
}

int fl(int a, int b){
	return a/b;
}

int main (){
	int t, d;
	scanf("%d %d %d %d", &n, &t, &k, &d);
	int res = div(n, k)*t;
	int ans = INT_MAX;
	int cnt = 0;
	for(int a=0;a<=10000000;a++){
		cnt =0;
		if(a >= d)
			cnt += fl(a-d, t)*k; 
		cnt += fl(a, t)*k;
		debug("t %d cnt %d\n", a, cnt);
		if(cnt >= n){
			ans = a;
			break;
		}
	}
	debug("res %d ans %d\n", res, ans);
	if(res <= ans)
		puts("NO");
	else
		puts("YES");
}
