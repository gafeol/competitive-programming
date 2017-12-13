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

const int MAXN = 3123;

int n;
char s[2][MAXN];
int mrk[2][MAXN];

int main (){
	scanf("%d", &n);
	mrk[0][0] = 1;
	for(int a=0;a<n;a++){
		int t = a&1;
		char mn = 'z';
		for(int b=0;b<=a;b++){
			scanf(" %c", &s[(a&1)][b]);
			mrk[t^1][b] = 0;
		}
		for(int b=0;b<=a;b++){
			if(mrk[t][b])
				mn = min(mn, s[(a&1)][b]);
		}
		printf("%c", mn);
		for(int b=0;b<=a;b++){
			if(!mrk[t][b] || s[t][b] != mn) continue;
			mrk[t^1][b] = 1;
			mrk[t^1][b+1] = 1;
		}
	}
}

