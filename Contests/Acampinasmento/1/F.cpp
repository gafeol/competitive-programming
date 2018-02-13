#include <bits/stdc++.h>
using namespace std;

int n, k;

int dp[60];

int main(){
	scanf("%d%d", &n, &k);
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	for(int a=3;a<=50;a++)
		dp[a] = dp[a-1] + dp[a-2];
	for(int i=n;i>0;i--){
		if(dp[i-1] >= k){
			printf("0");
		}
		else{
			printf("1");
			k -= dp[i-1];
		}
	}
	puts("");
}
