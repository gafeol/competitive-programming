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
int p, x;
int s[MAXN];

int main (){
	scanf("%d%d%d", &k, &p, &x);
	int t = sqrt((k*p)/x);
	double d;
	double ans = DBL_MAX;
	for(int aux=0;aux<1000000;aux++){
		if(t - aux <= 0) break;
		d = (k/((double)t-aux));
		ans = min(ans, d*p + (double)(t-aux)*x);	
	}
	for(int aux=0;aux<1000000;aux++){
		d = (k/((double)t+aux));
		ans = min(ans, d*p + (double)(t+aux)*x);	
	}
	printf("%.3f\n", ans);
}

