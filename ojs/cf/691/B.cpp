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
char s[MAXN], r[MAXN];

void quit(){
	puts("NIE");
	exit(0);
}

void mid(char m){
	if(m == 'A' || m == 'H' || m ==	'I' || m == 'M' || m == 'O' || m == 'o' || m == 'T' || m == 'U' || m == 'V' || m == 'v' || m == 'W' || m == 'w' || m == 'X' || m == 'x' || m == 'Y')
		return;
	quit();
}

int main (){
	scanf(" %s", s);
	for(char m='a';m<='z';m++){
		if(m == 'A' || m == 'H' || m ==	'I' || m == 'M' || m == 'O' || m == 'o' || m == 'T' || m == 'U' || m == 'V' || m == 'v' || m == 'W' || m == 'w' || m == 'X' || m == 'x' || m == 'Y')
			r[m] = m;
		if(m == 'b')
			r[m] = 'd';
		if(m == 'd')
			r[m] = 'b';
		if(m == 'p')
			r[m] = 'q';
		if(m == 'q')
			r[m] = 'p';

	}
	for(char m='A';m<='Z';m++){
		if(m == 'A' || m == 'H' || m ==	'I' || m == 'M' || m == 'O' || m == 'o' || m == 'T' || m == 'U' || m == 'V' || m == 'v' || m == 'W' || m == 'w' || m == 'X' || m == 'x' || m == 'Y')
			r[m] = m;

	}
	int tam = strlen(s);
	if(tam&1)
		mid(s[tam/2]);

	for(int a=0;a<tam/2;a++){
		if(r[s[a]] != s[tam-a-1])
			quit();
	}
	puts("TAK");
}
