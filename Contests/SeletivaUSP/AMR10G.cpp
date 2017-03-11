#include <bits/stdc++.h>
using namespace std;
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
		}
		sort(s, s+n);
		int res = INT_MAX;
		for(int a=0;a<=n-k;a++){
			res = min(res, s[a+k-1] - s[a]);
		}
		printf("%d\n", res); 
	}
}
