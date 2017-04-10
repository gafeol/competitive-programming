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

const int MAXN = 21234;

int n, m, k;
char s[MAXN];
int res;

void go(int i){
	res++;
	for(int a=i;a<i+k;a++){
		if(s[a] == '-')
			s[a] = '+';
		else
			s[a] = '-';
	}
}

int main (){
	for_tests(t, tt){
		scanf(" %s %d", s, &k);
		n = strlen(s);
		res = 0;
		for(int a=0;a<n;a++){
			if(s[a] == '-'){
				if(a + k > n){
					res = INT_MIN;
					break;
				}
				go(a);
			}
		}
		printf("Case #%d: ", tt);
		if(res < 0)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", res);
	}
}
