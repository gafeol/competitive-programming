#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fst first
#define snd second
#define pb push_back

const int MAXN = 3123, INF = 0x3f3f3f3f;

int n, pg, sp;

int s[MAXN][2], ind[MAXN];

vector<int> res[2];

int dp[MAXN][MAXN];

bool cmp(int a, int b){
	return s[a][1] > s[b][1];
}

int go(int i, int k){
	if(k > pg) return -INF;
	if(i == n) return (-INF)*(k != pg);
	if(dp[i][k] != -1) return dp[i][k];

	int &r = dp[i][k];

	int som = 0;
	if(i - k < sp) 
		som = s[ind[i]][1];

	r = max(go(i+1, k) + som, go(i+1, k+1) + s[ind[i]][0]);
	return r;
}

void solve(int i, int k){
	if(i == n) return ;

	int &r = dp[i][k];

	int som = 0;
	if(i - k < sp) 
		som = s[ind[i]][1];

	if(r == go(i+1, k) + som){
		if(som != 0) res[1].pb(ind[i]);
		solve(i+1, k);
	}
	else{
		res[0].pb(ind[i]);
		solve(i+1, k+1);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &pg, &sp);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a][0]);	
		ind[a] = a;
	}
	for(int a=0;a<n;a++)
		scanf("%d", &s[a][1]);

	sort(ind, ind+n, cmp);
	printf("%d\n", go(0, 0));	
	solve(0, 0);
	for(int t=0;t<2;t++){
		for(int u: res[t]){
			printf("%d ", u+1);
		}
		puts("");
	}
}
