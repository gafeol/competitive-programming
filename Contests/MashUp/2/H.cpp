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
int s[MAXN][2];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a][0] = c-'0';
	}
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a][1] = c-'0';
	}
	int res = 0;
	for(int a=0;a<n;a++){
		if(s[a][0]^s[a][1] == 0)
			continue;
		int b = a;
		while(b < n && s[b][0]^s[b][1] == 1)
			b++;
		a = b;
		res++;
	}
	printf("%d\n", res);
}
