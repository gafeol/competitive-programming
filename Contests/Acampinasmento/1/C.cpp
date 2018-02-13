#include<bits/stdc++.h>

using namespace std;

const int MAXN = 123;

int n, dp[MAXN][MAXN];

char s[MAXN], v[MAXN];
int ts, tv;

vector<int> a, b;

int go(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	if(i == ts || j == tv) return dp[i][j] = 0;
	if(s[i] == v[j]){
		dp[i][j] = go(i+1, j+1) + 1;
	}
	dp[i][j] = max(dp[i][j], go(i+1, j));
	dp[i][j] = max(dp[i][j], go(i, j+1));
	return dp[i][j];
}

void re(int i, int j){
	if(i == ts || j == tv) return ;
	if(s[i] == v[j]){
		a.push_back(i+1);
		b.push_back(j+1);
		re(i+1, j+1);
		return ;
	}
	if(dp[i][j] == go(i+1, j))
		re(i+1, j);
	else
		re(i, j+1);
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf(" %s %s", s, v); 
	ts = strlen(s);
	tv = strlen(v);
	printf("%d\n", go(0, 0));
	re(0, 0);
	for(int x: a){
		printf("%d ", x);
	}
	puts("");
	for(int x: b){
		printf("%d ", x);
	}
	puts("");
}
