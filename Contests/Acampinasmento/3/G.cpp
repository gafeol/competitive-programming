#include <bits/stdc++.h> 

using namespace std;

const int N = 1e4+5;

pair<int, int> v[N];
int main () {
	int n; scanf("%d", &n);
	if (n <= 3) {
		printf("0\n");
		return 0;
	}
	map<pair<int, int>, int> m;
	for (int i=0;i<n;i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[i] = make_pair(a, b);
		for (int j=0;j<i;j++) {
			if (++m[make_pair(a+v[j].first, b+v[j].second)] == 2) {
				printf("1\n");
				return 0;
			}
		}
	}
	printf("2\n");
	return 0;
}
