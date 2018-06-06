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

int n, m, k, nt;
int s[MAXN];

int main (){
	nt = 1;
	n = 7;
	int vl = 1000;
	k = ;
	printf("%d\n", nt);
	for(int t=0;t<nt;t++){
		printf("%d %d %d\n", n, k, n-1);
		for(int a=0;a<n;a++)
			printf("%d ", vl);
		puts("");
		for(int a=1;a<n;a++){
			printf("%d %d\n", (a-1)/2, a);
		}
	}
}

