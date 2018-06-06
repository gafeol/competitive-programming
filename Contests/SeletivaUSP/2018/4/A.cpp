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
	scanf("%d", &n);
	int ux = 0, uy  =0;
	int ok = 1;
	for(int a=0;a<n;a++){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if((abs(ux - x) + abs(uy - y)) <= t && (t-(abs(ux - x) + abs(uy - y)))%2 == 0)
			continue;
		else{
			ok = 0;	
		}
	}

	if(ok)
		puts("Yes");
	else
		puts("No");
}

