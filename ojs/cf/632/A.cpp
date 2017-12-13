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

const int MAXN = 45;

int n, m, k;
char s[MAXN][20];
char str[20];

ll p;

int main (){
	scanf("%d%lld", &n, &p);
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]); 
	}
	ll qtd = 0;
	ll res = 0;
	for(int a=n-1;a>=0;a--){
		if(strcmp(s[a], "half") == 0)
			qtd *= 2ll;
		else
			qtd = qtd*2ll + 1;
		res += (qtd*p)/2ll;
	}
	printf("%lld\n", res);
}

