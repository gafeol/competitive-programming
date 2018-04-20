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

const int MAXN = 212;

int n, m, k;
int s[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		memset(s, 0, sizeof(s));
		int a, b;
		int i = 2, j = 2;
		scanf("%d", &n);
		while((i+1)*3 < n){
			printf("%d %d\n", i, j);
			fflush(stdout);
			scanf("%d %d", &a, &b);
			s[a][b] = 1;
			while(s[i-1][j-1] + s[i-1][j] + s[i-1][j+1] == 3) i++;
		}
		while(1){
			printf("%d %d\n", i, j);
			fflush(stdout);
			scanf("%d %d", &a, &b);
			if(a + b == 0) break;
			s[a][b] = 1;
		}
	}
}

