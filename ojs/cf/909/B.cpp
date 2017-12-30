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
int s[MAXN];

int mrk[MAXN][MAXN];

int main (){
	scanf("%d", &n);
	for(int beg = 0;beg < n;beg++){
		for(int tam=1;tam<n;tam++){
			int i = beg;
			if(beg == 1)
				debug("n %d testa beg %d %d %d com %d %d\n", n, beg, tam, i, n-tam-2*beg, i+tam); 
			if(mrk[tam][i] == 0 && n-tam-2*beg > 0 && mrk[n-tam-2*beg][i+tam] == 0){ 
				mrk[tam][i] = 1;
				mrk[n-tam-2*beg][i+tam] = 1;
				debug("comb %d %d com %d %d\n", tam, i, n-tam-2*beg, i+tam);
			}
		}
	}
	ll res = 0;
	for(int tam=1;tam<=n;tam++){
		for(int i=0;i+tam-1<n;i++){
			res += (mrk[tam][i] == 0 ? 2 : 1);
		}
	}
	assert((res%2 == 0));
	res /= 2;
	printf("%lld\n", res);

}

