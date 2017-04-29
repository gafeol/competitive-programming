#include <bits/stdc++.h>
using namespace std;

multiset <int> a, b, c;
set <int> ans;
int v[5], p[5], x[200005], y[200005], z[200005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		v[0] = x[i];
		v[1] = y[i];
		v[2] = z[i];
		sort(v, v+3);
		b.insert(v[1]);
		c.insert(v[0]);
	}

	if (n == 1) {
		printf("1\n1");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		v[0] = x[i];
		v[1] = y[i];
		v[2] = z[i];
		sort(v, v+3);
		b.erase(b.find(v[1]));
		c.erase(c.find(v[0]));
		v[0] = *(b.rbegin());
		v[1] = *(c.rbegin());
		p[0] = x[i];
		p[1] = y[i];
		p[2] = z[i];
		sort(p, p+3);
		if (p[2] > v[0] && p[1] > v[1]) ans.insert(i+1);
		b.insert(p[1]);
		c.insert(p[0]);
	}

	printf("%d\n", (int)ans.size());
	for (set <int>::iterator it = ans.begin(); it != ans.end(); ++it)
		printf("%d ", *it);
	printf("\n");

	return 0;
}
