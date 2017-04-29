#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d", &n);
	int pa = -1, pb = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a > pa) {
			pb = max(pb, b);
			pa = a;
		}
	}
	
	printf("%d\n", pb);
	return 0;
}
