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
double s[MAXN], p[MAXN];

double d;

int main (){
	for_tests(t, tt){
		scanf("%lf %d", &d, &n);
		double time = 0;
		for(int a=0;a<n;a++){
			scanf("%lf %lf", &p[a], &s[a]);
			time = max(time, (d - p[a])/s[a]);
		}
		printf("Case #%d: %.10f\n", tt, d/time);
	}
}
