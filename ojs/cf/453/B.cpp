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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212, BM = (1<<17)+10;

int n, m, k;
int s[MAXN], dp[MAXN][BM], ind[MAXN], bm[MAXN];
vector<int> p;

int go(int i, int msk){
//	debug("go(%d %d)\n", i, msk);
	int &r = dp[i][msk];

	if(dp[i][msk] != -1)
		return dp[i][msk];

	if(i == n)
		return r = 0;

	r = INT_MAX;

	for(int a=1;a<=60;a++){
		if(bm[a]&msk) continue;
		r = min(r, go(i+1, msk|bm[a]) + abs(s[i] - a));
	}
//	debug("dp[%d][%d] = %d\n", i, msk, dp[i][msk]);
	return r;
}

void build(int i, int msk){
//	debug("build(%d %d)\n", i, msk);
	int &r = dp[i][msk];
	if(i == n)
		return ;
	for(int a=1;a<=60;a++){
		if(bm[a]&msk) continue;
		if(dp[i][msk] == go(i+1, msk|bm[a]) + abs(s[i] - a)){
			printf("%d ", a);
			build(i+1, msk|bm[a]);
			break;
		}
	}
}


int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	int deg = 0;
	for(int a=2;a<=100;a++){
		int ok = 1;
		for(int b=2;b<a;b++){	
			if(a%b == 0){
				ok = 0;
				break;
			}
		}
		if(ok){
			p.pb(a);
		//	debug("pri %d\n", a);
			ind[a] = deg++;
		}
	}
	debug("p %d\n", (int)p.size());
	bm[1] = 0;
	for(int a=2;a<=200;a++){
		int bma = 0;
		for(int pri: p){
			if(a%pri == 0)
				bma |= (1<<ind[pri]);
		}
		bm[a] = bma;
	}
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	go(0, 0);
	build(0, 0);
	putchar('\n');
}
