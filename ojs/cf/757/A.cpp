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

int n, m, k, i;
char s[MAXN], b[MAXN];

map<char, int> ind;

int main (){
	b[0] = 'B';
	b[1] = 'u';
	b[2] = 'l';
	b[3] = 'b';
	b[4] = 'a';
	b[5] = 's';
	b[6] = 'a';
	b[7] = 'u';
	b[8] = 'r';
	scanf(" %s", s);
	int tam = strlen(s);
	int res;
	i = 0;
	for(int a=0;a<tam;a++){
		ind[s[a]]++;
	}
	res = min(ind['B'], min(ind['a']/2, min(ind['u']/2, min(ind['s'], min(ind['l'], min(ind['b'], ind['r']))))));
	printf("%d\n", res);
}
