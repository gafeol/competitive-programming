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
char s[MAXN], v[MAXN];

int main (){
	scanf(" %s", s);
	if(s[0] == 'm')
		n = 0;
	else if(s[0] == 't' && s[1] == 'u')
		n = 1;
	else if(s[0] == 'w')
		n = 2;
	else if(s[0] == 't')
		n = 3;
	else if(s[0] == 'f')
		n = 4;
	else if(s[1] == 'a')
		n = 5;
	else
		n = 6;
	
	scanf(" %s", v);
	if(v[0] == 'm')
		m = 0;
	else if(v[0] == 't' && v[1] == 'u')
		m = 1;
	else if(v[0] == 'w')
		m = 2;
	else if(v[0] == 't')
		m = 3;
	else if(v[0] == 'f')
		m = 4;
	else if(v[1] == 'a')
		m = 5;
	else
		m = 6;
	if(m == (n + (28%7))%7 || m == (n + (30%7))%7 || m == (n + (31%7))%7)
		puts("YES");
	else
		puts("NO");
}
