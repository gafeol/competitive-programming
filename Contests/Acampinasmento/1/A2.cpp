#include <bits/stdc++.h>
using namespace std;

int n;

const int MAXN = 51234;

long long s[MAXN][2];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &s[a][0], &s[a][1]);
	}
	long long res = 0;
	for(int i=1;i<n-1;i++){
		res += (s[i][0] - s[0][0])*(s[i+1][1] - s[0][1]) - (s[i][1] - s[0][1])*(s[i+1][0] - s[0][0]);
	}
	if((res&1))
		printf("%lld.5\n", res/2ll);
	else
		printf("%lld\n", res/2ll);
}
