
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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;

inline ll mod(ll x) { return x % modn; }

const int MAXN = 312345;

int n, np; 

int main(){
	n = 300000;
	printf("%d %d\n", n, n);
	for(int a=0;a<n;a++)
		printf("%d ", 1);
	puts("");
	for(int a=0;a<n;a++)
		printf("1000000000 ");
	puts("");
	printf("%d\n", n);
	for(int a=0;a<n;a++)
		printf("%d %d 1000000000\n", 1, n); 
}
