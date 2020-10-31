
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

long long n, k;

long long bs() {
	long long l = 0, m, r = 1000000000;
	while(l < r) {
		m = (l+r)/2ll;
		if (m*m + m <= 2*k) {
			l = m+1;
		}
		else r = m;
	}
	return l-1;
}

int main (){
	scanf("%lld %lld", &n, &k);
	if (k == 0) printf("()");
	n--;
	vector<long long> resp;
	long long mx = 0;
	while(k && n) {
		if (mx == 0) {
			long long p = bs();
			k -= ((1ll+p)*p)/2ll;
			if ((mx == 0 && n>=p) || (mx != 0 && n)) {
				n -= (mx == 0) ? p : 1;
				mx = max(mx, p);
				resp.push_back(p);
			}
			else {
				printf("Impossible\n");
				return 0;
			}
		}
		else {
			long long p = min(mx, k);
			resp.push_back(p);
			n-=1;
			k-=p;
		}
	}
	sort(resp.begin(), resp.end());
	if (k == 0) {
		long long b = 0;
			for (long long i = 0;i<mx;i++) {
				printf("(");
				while( (b < resp.size() && i+1 == resp[b]) ) {
					b++;
					printf("()");
				}
			}
			for (long long i = 0;i<mx;i++) {
				printf(")");
			}
		if (n != 0) {
			while(n--) printf("()");
		}
	}
	else {
		printf("Impossible\n");
		return 0;
	}
	printf("\n");
}

