#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;

vector<int> p;
int ip[N];

int main() {
	for (int i=2; i < N; i++) {
		if (ip[i] == 0) {
			p.push_back(i);
			for (int j=i;j < N;j += i) {
				ip[j] = 1;
			}
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", p[n-1]);
}
