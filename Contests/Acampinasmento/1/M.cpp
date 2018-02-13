#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	ll x1, x2, y1, y2;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	a = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	b = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	ll resp;
	map<ll, int> ma;
	for (ll i = 1; i < 1e5; i++) {
		ma[i*i] = 1;
	}
	for (ll i = 1; i < 1e5; i++) {
		if (i*i > a) {
			printf("NO\n");
			return 0;
		}
		if (a%(i*i) == 0) {
			ll x = a/(i*i);
			if (b >= x && b%x == 0) {
				if (ma[b/x] == 1) {
					resp = x;
					printf("YES\n%lf\n", sqrt(resp));
					return 0;
				}
			}
		}
	}
}
