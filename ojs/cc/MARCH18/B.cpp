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

const int MAXN = 212345, MASK = 31;

int n, m, k;
int s[MAXN];

int acu[MAXN][MASK];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		if(a > 0)
			for(int i=0;i<MASK;i++)
				acu[a][i] = acu[a-1][i];
		for(int i=0;i<MASK;i++){
			acu[a][i] += ((s[a]&(1<<i)) > 0);
		}
	}
	for(int a=0;a<m;a++){
		int i, j;
		int aux[MASK];
		scanf("%d %d", &i, &j);
		i--;
		j--;
		for(int a=0;a<MASK;a++){
			aux[a] = acu[j][a] - (i > 0 ? acu[i-1][a] : 0);
		}
		int res = 0;
		for(int a=0;a<MASK;a++)
			if(aux[a] <= (j-i+1)/2 - ((j-i+1)%2==0)){
				res += (1<<a);
			}
		printf("%d\n", res);
	}
}

