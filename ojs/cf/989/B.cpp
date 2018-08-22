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

int seen[MAXN];

char inv(char c){
	if(c == '0')
		return '1';
	return '0';
}


int main (){
	scanf("%d%d", &n, &k);
	int p = k;

	for(int a=0;a<n;a++){
		scanf(" %c", s+a);
	}
	int ok = 0;
	for(int a=0;a<n-p;a++){
		if(s[a] == '.' && s[a+p] != '.')
			s[a] = inv(s[a+p]);
		if(s[a] != '.' && s[a+p] == '.')
			s[a+p] = inv(s[a]);
		if(s[a] == '.' && s[a+p] == '.'){
			s[a] = '1';
			s[a+p] = '0';
		}
		if(s[a] != s[a+p])
			ok = 1;
	}
	if(ok){
		for(int a=0;a<n;a++)
			printf("%c", (s[a] == '.' ? '0' : s[a]));
	}
	else
		puts("No");
}

