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

const int MAXN = 1000000;
const int MAXK = 13;

int n, m, k;
int val[MAXN+10];
int dp[MAXN+10];
int res[MAXK+10][MAXN+10];

int P;

void crivo()
{
	for(int i = 2; i <= MAXN; i++) {
		if(val[i] == 0) {
			for(int j = 2*i; j <= MAXN; j += i) {
				val[j] += i;
			}
		}
	}
	dp[2] = 1;
	dp[0] = 0;
	for(int i = 3; i <= MAXN; i++) {
		dp[i] = dp[val[i]] + 1; 
	}
	for(int i = 0; i <= MAXK; i++) {
		for(int j = 2; j <= MAXN; j++) {
			res[i][j] = res[i][j-1];
			if(dp[j] == i)
				res[i][j]++;
		}
	}
}

int main (){
	crivo();
	int A, B, K, P;
	scanf("%d", &P);
	for(int i = 0; i < P; i++) {
		scanf("%d %d %d", &A, &B, &K);
		if(K > MAXK) printf("0\n");
		else printf("%d\n", res[K][B] - res[K][A-1]);
	}
	return 0;
}
