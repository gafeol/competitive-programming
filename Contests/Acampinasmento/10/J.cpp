
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000002, INF = 0x3f3f3f3f;

int dp[MAXN][3][3];

char s[MAXN];
int n;

int in(int i, char c){
	if(i == 0){
		if(c == 'P') return -1;
		if(c == 'N') return 1;
	}
	else if(i == 1){
		if(c == 'K') return 1;
		if(c == 'N') return -1;
	}
	else{
		if(c == 'K') return -1;
		if(c == 'P') return 1;
	}
	return 0;
}

int go(int i, int k, int c){
	if(i == n) return 0;
	int &r = dp[i][k][c];
	if(r != INF) return r;
	r = 0;
	int g = in(c, s[i]);
	r = go(i+1, k, c);
	if(k > 0)
		r = max(r, max(max(go(i+1, k-1, 0), go(i+1, k-1, 1)), go(i+1, k-1, 2))); 
	r += g;
	return r;
}

int main (){
	memset(dp, INF, sizeof(dp));
	scanf(" %s", s);
	n = strlen(s);
	for(int a=0;a<3;a++){
		if(max(max(go(0, a, 1), go(0, a, 0)), go(0, a, 2)) > 0){
			printf("%d\n", a);
			return 0;
		}
	}
}
