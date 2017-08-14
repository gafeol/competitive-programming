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

const int MAXN = 212345;

int n, m, k;
int mrk[MAXN];

int main (){
	scanf("%d %d", &n, &k);
	int o = n - k;
	if(o == 1){
		puts("2");
		for(int a=2;a<=n;a++){
			printf("1 %d\n", a);
		}
		return 0;
	}
	int ch = min(o-1, k);
	int sz1 = 0, sz2 = 0;
	sz1 = (o-1)/ch + ((o-1)%ch != 0);
	if(ch > 1){
		debug("o %d sz1 %d ch %d\n", o, sz1, ch);
		sz2 = (o-1-sz1)/(ch-1) + ((o-1-sz1)%(ch-1) != 0);
		debug("sz2 = %d/%d + %d = %d\n", (o-1-sz1), (ch-1), ((o-1-sz1)%(ch-1) != 0), sz2);
	}
	
	debug("%d %d\n", sz1, sz2);
	int ind = 0;
	printf("%d\n", sz1+sz2 + 2);
	for(int a=2;a<=o;a++){
		debug("girando ");
		printf("%d %d\n", a, max(1, a - ch));
		mrk[max(1, a-ch)]++;
		mrk[a]++;
	}
	for(int a=1;a<=n;a++){
		if(mrk[a] == 1){
			debug("folha ");
			printf("%d %d\n", a, n-ind);
			mrk[n-ind] = 2;
			ind++;
		}
	}
	for(int a=1;a<=n;a++){
		if(mrk[a] == 0)
			printf("%d 1\n", a);
	}
	
}
