#include <bits/stdc++.h>
using namespace std;

#define int long long 

typedef pair<int, int> pii;
#define fst first
#define snd second

const int MAXT = 2123;
const int MAXN = MAXT;

int n, m;

pii dp[MAXN][MAXT];

pii s[MAXN];

pii best(pii a, pii b){
	if(a.fst > b.fst)
		return a;
	else if(a.fst < b.fst)
		return b;

	if(a.snd < b.snd)
		return a;
	else
		return b;
}

pii so(pii a, pii b){
	return pii(a.fst + b.fst, a.snd + b.snd);
}
int ind[MAXN];

pii go(int i, int t){
	if(i == n) return pii(0, 0);
	if(dp[i][t].fst != -1)
		return dp[i][t];
	int tt = s[ind[i]].fst;
	if(t + s[ind[i]].fst <= m)
		dp[i][t] = best(dp[i][t], so(go(i+1, t+s[ind[i]].fst), pii(s[ind[i]].snd, (t+s[ind[i]].fst)*s[ind[i]].snd)));
	dp[i][t] = best(dp[i][t], go(i+1, t));
	return dp[i][t];
}

vector<int> ans;

void re(int i, int t){
	if(i == n) return ;
	if(t + s[ind[i]].fst <= m){
		if(dp[i][t] == so(go(i+1, t+s[ind[i]].fst), pii(s[ind[i]].snd, (t+s[ind[i]].fst)*s[ind[i]].snd))){
			ans.push_back(ind[i]+1);
			re(i+1, t+s[ind[i]].fst);
			return ;
		}
	}
	assert(dp[i][t] == go(i+1, t));
	re(i+1, t);
}


bool cmp(int aa, int bb){
	pii a = s[aa], b = s[bb];
	return a.fst*b.snd < a.snd*b.fst;
}

main (){
	scanf("%lld%lld", &n, &m);
	for(int a=0;a<MAXN;a++){
		for(int b=0;b<MAXT;b++){
			dp[a][b] = pii(-1, -1);
		}
	}
	for(int a=0;a<n;a++){
		ind[a] = a;
		scanf("%lld %lld", &s[a].fst, &s[a].snd);
	}
	sort(ind, ind+n, cmp);
	go(0, 0);
	re(0, 0);
	printf("%lld\n", (long long)ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%lld ", ans[i]);
	}
	puts("");
}

