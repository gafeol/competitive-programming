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

const int MAXN = 12;

int n, m, k;

char s[2][MAXN];
char kl[MAXN], sb[MAXN];

int main (){
	scanf(" %s %s", s[0], s[1]);
	scanf("%d", &n);
	printf("%s %s\n", s[0], s[1]);
	for(int a=0;a<n;a++){
		scanf(" %s %s", kl, sb);
		if(strcmp(s[0], kl) == 0)
			strcpy(s[0], sb);
		else
			strcpy(s[1], sb);
		printf("%s %s\n", s[0], s[1]);

	}
}
