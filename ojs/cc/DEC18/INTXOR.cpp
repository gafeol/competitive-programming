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

int test(int a, int b, int c){
	printf("1 %d %d %d\n", a, b, c);
	fflush(stdout);

	int x;
	scanf("%d", &x);
	if(x == -1)
		exit(0);
	return x;
}

int x[MAXN];

void solve7(int ini){
	for(int ii=0;ii<7;ii++){
		int i = ii + ini;
		x[i] = test(ini + ii, ini + (ii+1)%7, ini + (ii+2)%7);
	}
	x[ini+5] ^= (x[ini]^x[ini+1]^x[ini+3]^x[ini+4]);
	x[ini+6] ^= (x[ini]^x[ini+2]^x[ini+3]^x[ini+5]);
	for(int ii = 4;ii>=0;ii--){
		x[ini+ii] ^= (x[ini+ii+1]^x[ini+ii+2]);
	}
}

void solve5(int ini){
	int i =   test(ini, ini+1, ini+2);
	int ii =  test(ini+1, ini+2, ini+3);
	int iii = test(ini+2, ini+3, ini+4);
	int iv =  test(ini, ini+1, ini+4);
	int v =   test(ini, ini+3, ini+4);

	x[ini+3] = (i^iii^iv);
	x[ini] = (x[ini+3]^i^ii);
	x[ini+4] = (x[ini]^x[ini+3]^v);
	x[ini+2] = (iii^x[ini+3]^x[ini+4]);
	x[ini+1] = (ii^x[ini+2]^x[ini+3]);
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);


		int ini = 1;
		while((n - ini + 1)%5 != 0){
			if(n - ini + 1 == 7){
				break;
			}
			int i = test(ini, ini+1, ini+2);	
			int ii = test(ini+1, ini+2, ini+3);
			int iii = test(ini, ini+1, ini+3);
			int iv = test(ini, ini+2, ini+3);

			x[ini+1] = (i^ii^iii);
			x[ini+2] = (x[ini+1]^iii^iv);
			x[ini+3] = (ii^x[ini+1]^x[ini+2]);
			x[ini] = (iv^x[ini+2]^x[ini+3]);
			ini += 4;
		}

		if((n - ini + 1) == 7)
			solve7(ini);
		else{
			while(n - ini + 1 > 0){
				solve5(ini);
				ini += 5;
			}

		}

		printf("2");
		for(int a=1;a<=n;a++)
			printf(" %d", x[a]);
		puts("");
		fflush(stdout);

		int v;
		scanf("%d", &v);
		if(v == -1)
			return 0;
	}
}

