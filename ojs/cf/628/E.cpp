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

const int MAXN = 6123;

int n, m, k;
int s[MAXN], M[MAXN][MAXN];
int l[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &c);
			M[a][b] = (c == 'z');
			l[b] = l[b-1] + M[a][b];
		}
	}
	int i = 1, j = 1;
	while(i != n && j != m+1){
		int ii = i, jj = j;
		while(ii > 0){

		}
		if(i+1 <= n) i++;
		else j++;
	}
}
