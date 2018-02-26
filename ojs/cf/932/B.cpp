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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

int dp[MAXN];
int acu[MAXN][10];

int f(int x){
	if(x < 10) return x;
	else{
		int p = 1;
		while(x > 0){
			if(x%10 != 0)
				p *= (x%10);
			x/=10;
		}
		return f(p);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=1000010;a++){
		for(int d=0;d<10;d++)
			acu[a][d] = acu[a-1][d];
		acu[a][f(a)]++;
	}
	for(int a=0;a<n;a++){
		int l, r;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", acu[r][k] - acu[l-1][k]);
	}
}

