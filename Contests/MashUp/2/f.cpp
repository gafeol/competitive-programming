#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[200005], tmp[200005];
int main() {
	ll n, p, q, x;
	scanf("%lld %lld %lld", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	ll l = 0, r = 1000000100ll, m = (l+r)/2ll;

	while (l < r) {
		m = (l+r)/2ll;
		for (int i = 0; i < n; i++) {
			tmp[i] = v[i];
		}
		ll cont = 0;
		int ok = 0;
		for (int i = 0; i < n; i++) {
			tmp[i] -= m*q;
			if (tmp[i] > 0) {
				if (p-q == 0) {
					l = m+1ll;
					ok = 1;
					break;
				}
				cont += tmp[i]/(p-q) + (tmp[i]%(p-q) == 0 ? 0:1);
			}
		}
		if (ok) continue;
		if (cont > m) l = m+1ll;
		else r = m;
	}

	printf("%lld\n", l);
	return 0;
}
