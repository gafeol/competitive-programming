#include <bits/stdc++.h> 

using namespace std;
const int N = 1e5;

long long f[N];

int main() {
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	for (int i=3;i < N; i++) {
		f[i] = f[i-1] + f[i-3];
	}
	int j;
	scanf("%d", &j);
	printf("%lld\n", f[j]);
}
