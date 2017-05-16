#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int INF = -10000000;

#define c1 fst.fst
#define i1 fst.snd
#define c2 snd.fst
#define i2 snd.snd

int n, m, k;
int c, d;
int s[MAXN], cus[MAXN];
char ch[MAXN];

vector<pii> mo[2];

ppp dp[2][MAXN];

bool menor(pii a, pii b){
	swap(a.fst, a.snd);
	swap(b.fst, b.snd);
	a.fst = s[a.fst];
	b.fst = s[b.fst];
	debug("men %d %d <= %d %d  %d\n", a.fst, a.snd, b.fst, b.snd, (a<=b));
	return (a <= b);
}

void print(int i, int j){
	debug("dp[%d][%d] %d %d %d %d\n", i, j, dp[i][j].i1, dp[i][j].c1, dp[i][j].i2, dp[i][j].c2);
}

void upd(int t, int i, int j){
	if(menor(dp[t][i].fst, mo[t][j])){
		debug("upd %d %d\n", t, i);
		dp[t][i].snd = dp[t][i].fst;
		dp[t][i].fst = mo[t][j];
		print(t, i);
	}
	else if(menor(dp[t][i].snd, mo[t][j])){
		dp[t][i].snd = mo[t][j];
	}
}

int val(int t, int i, int j){
	if(dp[t][i].i1 == 0 || dp[t][j].i1 == 0) return INF;
	if(dp[t][i].i1 == dp[t][j].i1){
		if(dp[t][j].i2 == 0 && dp[t][i].i2 == 0)
			return INF;
		else if(dp[t][j].i2 == 0)
			return s[dp[t][i].i2] + s[dp[t][j].i1];
		return s[dp[t][i].i1] + s[dp[t][j].i2];
	}
	return s[dp[t][i].i1] + s[dp[t][j].i1];
}

int main (){
	scanf("%d %d %d", &n, &c, &d);
	s[0] = INF;
	for(int a=1;a<=n;a++){
		scanf("%d %d %c", &s[a], &cus[a], &ch[a]); 
		mo[ch[a] == 'D'].pb(pii(cus[a], a));
	}
	sort(mo[0].begin(), mo[0].end());
	sort(mo[1].begin(), mo[1].end());
	for(int t=0;t<2;t++){
		int j = 0;
		dp[t][0] = ppp(pii(0, 0), pii(0, 0));
		for(int i=0;i<MAXN;i++){
			if(i > 0) dp[t][i] = dp[t][i-1];
			while(j < mo[t].size() && mo[t][j].fst <= i){
				upd(t, i, j);
				j++;
			}
			if(i <= 10){
				debug("dp[%d][%d] %d %d %d %d\n", t, i, dp[t][i].i1, dp[t][i].c1, dp[t][i].i2, dp[t][i].c2);
			}
		}
	}
	int res = INF;
	for(int a=0;a<c;a++){
		debug("C a %d aa %d val %d\n", a, c-a, val(0, a, c - a));
		res = max(res, val(0, a, c - a));
	}
	for(int a=0;a<d;a++){
		debug("D a %d val %d\n", a, val(1, a, d - a));
		res = max(res, val(1, a, d - a)); 
	}
	debug("s[%d] %d s[%d] %d\n", dp[0][c].i1, s[dp[0][c].i1], dp[1][d].i2, s[dp[1][d].i2]);
	res = max(res, s[dp[0][c].i1] + s[dp[1][d].i1]);
	if(res < 0)
		puts("0");
	else
		printf("%d\n", res);
}
