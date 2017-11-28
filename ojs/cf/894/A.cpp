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
int n, m, k;

int main (){
	scanf(" %s", s);
	n = strlen(s);
	int res = 0;
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			for(int c=b+1;c<n;c++){
				if(s[a] == 'Q' && s[b] == 'A' && s[c] == 'Q')
					res++;
			}
		}
	}
	printf("%d\n", res);
}

