#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main (){
	freopen("jenga.in", "r", stdin);
	scanf("%d", &n);
	for(int t=1;t<=n;t++){
		int x;
		scanf("%d", &x);
		printf("Case %d: ", t);
		if(x%3)
			puts("Bakkar");
		else
			puts("Wahdan");
	}
}

