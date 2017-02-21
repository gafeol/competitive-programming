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

char s[MAXN];
int n;

int main (){
	scanf(" %s", s);
	int n = strlen(s);
	s[n] = '?';
	for(int a=0;a<n;a++){
		if(a != 0){
			if(s[a] == s[a-1]){
				if('a' != s[a-1] && 'a' != s[a+1])
					s[a] = 'a';
				else if('b' != s[a-1] && 'b' != s[a+1])
					s[a] = 'b';
				else
					s[a] = 'c';
			}
		}
		printf("%c", s[a]);
	}
}
