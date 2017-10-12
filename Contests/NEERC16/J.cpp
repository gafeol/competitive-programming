
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fst first
#define snd second
#define pb push_back

int s[MAXN], v[MAXN];

int dp[MAXN][MAXN][MAXN*MAXN];

int sum;

int n;

int ind[MAXN];

bool cmp(int a, int b){
	return v[a] > v[b];
}

int go(int i, int k, int sum){
	if(i == n && k >= 0 && sum == 0) return 0;
	if(k < 0 || i == n) return INF;
	if(dp[i][k][sum] != -1) return dp[i][k][sum];

	int &r = dp[i][k][sum];

	dp[i][k][sum] = min(go(i+1, k, sum)+s[i], go(i+1, k-1, max(0, sum-v[i])));
	return r;
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		sum += s[a];
	}
	int S = sum;
	for(int a=0;a<n;a++){
		scanf("%d", v+a);
		ind[a] = a;
	}
	sort(ind, ind+n, cmp);
	int k = 0;
	for(int ii=0;ii<n;ii++){
		int i = ind[ii];	
		sum -= v[i];
		k++;
		if(sum <= 0)
			break;
	}
	printf("%d %d\n", k, go(0, k, S));
	
}
