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
int s[MAXN];
const int SUM = 0, SUB = 1, MUL = 2;
char ope[5];

inline void print(int a, int b, int op){
	int res;
	if(op == SUM)
		res = a + b;
	else if(op == SUB)
		res = a - b;
	else
		res = a*b;
	printf("%d %c %d = %d\n", a, ope[op], b, res); 
}


int main (){
	ope[0] = '+';
	ope[1] = '-';
	ope[2] = '*';
	scanf("%d", &n);
	if(n < 4){
		puts("NO");
		return 0;
	}
	puts("YES");
	while(n > 5){
		printf("%d - %d = %d\n", n, n-1, 1); 
		printf("%d * %d = %d\n", 1, n-2, n-2);
		n = n-2;
	}
	if(n == 5){
		print(3, 2, SUB);
		print(5, 1, SUM);
		print(6, 4, MUL);
		print(24, 1, MUL);
	}
	else{
		print(1, 2, MUL);
		print(2, 3, MUL);
		print(6, 4, MUL);
	}
}
