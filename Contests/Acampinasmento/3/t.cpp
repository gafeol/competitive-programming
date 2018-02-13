#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	if (n == 0) return 1;
	else return n*f(n-1);
}

int calcG(vector<int> g, int n, int m) {
	int r = 0;
	for (int i=0;i<m-1;i++) {
		for (int j=0;j<n;j++) {
			r += abs(g[n*i+j] - g[n*(i+1)+j]);
		}
	}
	for (int i=0;i<n-1;i++) {
		for (int j=0;j<m;j++) {
			r += abs(g[n*j+i] - g[n*j+i+1]);
		}
	}
	for (int i=0;i<n;i++) {
		r += g[i] + g[(m-1)*n+i];
	}
	for (int i=0;i<m;i++) {
		r += g[n*i] + g[i*n+n-1];
	}
	return r;
}

int main() {
	/*
	int gf[9] = {169, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> g(gf, gf + 9);
	int mn = 6000;
	vector<int> mni;
	for (int i=0;i<f(9);i++) {
		if (mn > calcG(g)) {
			mn = calcG(g);
			mni = g;
		}
		next_permutation(g.begin(), g.end());
	}
	printf("%d - ", mn);
	for (int i=0;i<9;i++) {
		printf("%d ", g[i]);
	}
	*/
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> g;
	for (int i=0;i<n*m;i++) {
		int a;
		scanf("%d", &a);
		g.push_back(a);
	}
	sort(g.begin(), g.end());
	printf("%d\n", calcG(g, n, m));
}
