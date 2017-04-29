#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <ll, ll> mp;
ll v[200005];
int main() {
	ll n, s, sum = 0;
	scanf("%lld %lld", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	mp[0] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		ll y = sum-s;
		//if (mp[y] != 0) printf("mp[%lld] = %lld\n", y, mp[y]);
		ans += mp[y];
		mp[sum]++;
	}

	printf("%lld\n", ans);
	return 0;
}
