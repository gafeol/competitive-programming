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
	int res = 0;
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			int x = a^b;
			if(x < a || x < b) continue; 
			if(x <= n && x > 0 && a < b+x && b < a+x && x < a+b){
				res++;
			}
		}
	}
	printf("%d\n", res);
}

