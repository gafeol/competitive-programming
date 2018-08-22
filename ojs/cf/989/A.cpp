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

char s[MAXN];

bool d(char c){
	return (c == '.');
}
int main (){
	scanf(" %s", s);
	n = strlen(s);
	for(int a=1;a<n-1;a++){
		if(!d(s[a-1]) && !d(s[a]) && !d(s[a+1]) && s[a-1] != s[a] && s[a] != s[a+1] && s[a-1] != s[a+1]){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}

