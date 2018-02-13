#include <bits/stdc++.h>

using namespace std;

int v[5], inp[5];

int main() {
	int n;
	scanf("%d", &n);
	v[0]=v[1]=-1e9;
	v[2]=v[3]=1e9;
	for (int i=0;i<n;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d", &inp[j]);
		}
		for (int j=0;j<4;j++) {
			int a = inp[j];
			if (j < 2) v[j] = max(v[j], a);
			else v[j] = min(v[j], a);
		}
		if (v[0] >= v[2] || v[1] >= v[3]) {
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n", (v[3]-v[1])*(v[2]-v[0]));
}
