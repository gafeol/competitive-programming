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

const int MAXN = 5123;
const int MAXM = 112345;


int n, m, k;
int s[MAXN][MAXN], mx[MAXN][MAXN];


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s[0]+a);
		mx[0][a] = s[0][a];
	}
	for(int t=1;t<n;t++){
		for(int a=0;a<n-t;a++){
			int i = t;
			s[i][a] = s[i-1][a]^s[i-1][a+1];	
			mx[i][a] = max(s[i][a], max(mx[i-1][a], mx[i-1][a+1]));
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		i--;
		j--;
		int t = j - i;
		printf("%d\n", mx[t][i]);
	}
}

