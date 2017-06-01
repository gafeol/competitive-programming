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

int main (){
	scanf("%d%d", &n, &k);
	if(k > 3){
		puts("No");
		return 0;
	}
	if(n == 0){
		if(k == 1){
			puts("Yes");
			printf("0 1\n");
		}
		else if(k == 0){
			puts("Yes");
			printf("1 1\n");
		}
		else
			puts("No");
		return 0;
	}
	if(k == 2){
		printf("Yes\n%d %d\n", n, n);
	}
	else if(k == 1){
		puts("Yes");
		if(n < 0)
			printf("%d -10000000\n", n);
		else
			printf("%d 10000000\n", n);
	}
	else if(k == 3){
		printf("Yes\n%d %d\n", -n, n);
	}
	else{
		printf("Yes\n");
		printf("0 0\n");
	}
}
