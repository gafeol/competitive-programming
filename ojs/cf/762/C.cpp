#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN], nd[MAXN];
int dp[MAXN][2];
int tn, ts;

int bb(int i, int j, int val){
	while(i < j){
		int m = (i + j)/2;
		if(dp[m][1] > val)
			j = m;
		else
			i = m+1;
	}
	if(dp[i][1] <= val)
		i = tn;
	return i;
}

int main (){
	scanf(" %s", s);
	scanf(" %s", nd);
	ts = strlen(s);
	tn = strlen(nd);
	int i = 0, j = 0;
	while(j < tn){
		while(i < ts && s[i] != nd[j])
			i++;
		dp[j][0] = i;
		i = min(i+1, ts);
		j++;
	}
	i = ts-1;
	j = tn-1;
	while(j >= 0){
		while(i >= 0 && s[i] != nd[j])
			i--;
		dp[j][1] = i;
		i = max(-1, i-1);
		j--;
	}
	int res = 0;
	for(int b=0;b<2;b++){
		for(int a=0;a<tn;a++){
			debug("%d ", dp[a][b]);
		}
		debug("\n");
	}
	for(int a=0;a<tn;a++){
		if(dp[a][0] == ts) break;
		int i = bb(a+1, tn-1, dp[a][0]);
		res = max(res, a + tn - i);
	}
	for(int a=tn-1;a>=0;a--){
		if(dp[a][1] == -1) break;
		res = max(res, tn - a); 
	}

	debug("%d\n", res);
	for(int a=0;a<tn;a++){
		if(dp[a][0] == ts) break;
		int i = bb(a+1, tn-1, dp[a][0]);
		if(res == a + tn - i){
			for(int x=0;x<=a;x++){
				printf("%c", nd[x]);
			}
			for(int x = i;x<tn;x++){
				printf("%c", nd[x]);
			}
			return 0;
		}
	}
	for(int a=tn-1;a>=0;a--){
		if(dp[a][1] == -1) break;
		if(res == tn - a){
			for(int x=a;x<tn;x++){
				printf("%c", nd[x]);
			}
		}
	}
	if(res == 0){
		printf("-");
	}
	printf("\n");
}
