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
char s[2][MAXN];

ll h[2][MAXN];

inline ll l(char c){
	return (kk)(c - 'a');
}

int main (){
	scanf(" %s %s", s[0], s[1]);

	n = strlen(s[0]);
	m = strlen(s[1]);

	for(int a=0;a<2;a++){
		h[a][0] = 0;
		for(int i = 0;i < (a == 0 ? n:m);i++){
			if(i != 0) h[a][i] = mod(h[a][i-1]*26ll); 
			h[a][i] = mod(h[a][i] + l(s[a][i]));
		}
	}
}
