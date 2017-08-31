
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
int s[MAXN];

int main (){
	freopen("zeriba.in", "r", stdin);
	int t;
	scanf("%d", &t);
	long double pi = acos(-1.0);
	for (int i=1;i<=t;i++) {
		scanf("%d", &n);
		int mx = 0;
		int sum = 0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			mx = max(mx, s[a]);
			sum += s[a];
		}
		int flag = 1;
		for(int a=0;a<n;a++){
			if (s[a] >= sum-s[a]) {
				flag = 0;
			}
		}
		long double l = (long double)mx/2.0, r = 1000000.0;
		for (int j=0;j<100;j++) {
			if (!flag) break;
			long double med = (l+r)/2.0;
			long double current = 0;
			for (int k=0;k<n;k++) {
				long double theta = asin((long double)s[k]/(2.0*med));
				current += 2*theta;
				//printf("%Lf %Lf -> %d\n", theta, current, k);
				if (current > 2*pi) {
					break;
				}
			}
			if (current > 2*pi) l = med;
			else {r = med;}
		}
		printf("Case %d: ", i);
		if (flag) printf("%.4Lf\n", l);
		else printf("can't form a convex polygon\n");
	}
}

