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
char s[MAXN][3];
char p[5];

int main (){
	scanf(" %s", p);
	scanf("%d", &n);
	int ok = 0, lst = 0, beg = 0;
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
		if(s[a][1] == p[1] && s[a][0] == p[0])
			ok = 1;
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			if(s[a][1] == p[0] && s[b][0] == p[1])
				ok = 1;
		}
	}
	if(ok)
		puts("YES");
	else
		puts("NO");
}

