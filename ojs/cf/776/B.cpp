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
	if(n == 1){
		puts("1\n1");
		return 0;
	}
	else if(n == 2){
		puts("1\n1 1\n");
		return 0;
	}
	else{
		printf("2\n");
		for(ll a=2;a<=n+1;a++){
			if(s[a] == 0){
				for(ll b=a;b*a <= n+1;b++){
					s[a*b] = 1;
				}
			}
			printf("%d ", s[a]+1);
		}
	}
}
