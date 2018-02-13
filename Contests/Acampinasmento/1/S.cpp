#include <bits/stdc++.h>

using namespace std;

long long calc(long long a, long long b) {
	return (max(0ll, b-a));
}

int main() {
	int n;
	scanf("%d", &n);
	long long last = -1e9-1;
	long long sum = 0;
	vector<pair<long long, long long> > v;
	for (int i=0;i<n;i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (b < a) swap(a, b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i=0;i<n;i++) {
		long long a = v[i].first;
		long long b = v[i].second;
		a = max(a, last);
		sum += calc(a, b);
		last = max(b, last);
	}
	printf("%lld\n", sum);
}
