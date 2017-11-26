
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

const int MAXN = 21;
int v, mn;
int n, m, k;
int s[MAXN][MAXN];
int acu[MAXN][MAXN];

int main (){
	scanf("%d%d %d %d", &n, &m, &v, &mn);
	for(int a=0;a<v;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		s[i][j] = 1;
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			acu[a][b] = acu[a-1][b] + acu[a][b-1] - acu[a-1][b-1] + s[a][b];
		}
	}
	int res = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			for(int c=a;c<=n;c++){
				for(int d=b;d<=m;d++){
					if(acu[c][d] - acu[a-1][d] - acu[c][b-1] + acu[a-1][b-1] >= mn)
						res++;
				}
			}
		}
	}
	printf("%d\n", res);
}

