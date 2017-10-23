
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

int a[MAXN], b[MAXN];

int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int i=0;i<n;i++){
		a[i+1] = a[i];
		b[i+1] = b[i];
		a[i+1] += (s[i] == 'a');
		b[i+1] += (s[i] == 'b');
	}
	int res = max(b[n], a[n]);
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			res = max(res, a[n] - a[j] + b[j] - b[i] + a[i]);	
			debug("i %d j %d res %d\n", i, j, a[n] - a[j] + b[j] - b[i] + a[i]);
		}
	}
	printf("%d\n", res);
}

