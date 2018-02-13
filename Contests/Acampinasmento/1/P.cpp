#include <bits/stdc++.h> 

using namespace std;

int k[10000];

int f(int x) {
	if (x == 1) return 1;
	else return x*f(x-1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		k[i] = i+1;
	}
	int t = 0;
	for (int i=0;i<f(n);i++) {
		for (int j=0;j<n;j++) {
			printf("%d ", k[j]);
		} printf("\n");
		swap(k[t], k[t+1]);
		t++;
		t%=(n-1);
	}
}
