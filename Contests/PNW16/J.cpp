
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

const int MAXN = 212345, LOGN = 19;

int n, m, k;
ll s[MAXN];

int nxt[MAXN][LOGN];
ll mn[MAXN][LOGN];

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
		nxt[a][0] = min(n-1, a+1);
		mn[a][0] = s[a];
	}
	for(int lg=1;lg<LOGN;lg++){
		for(int a=0;a<n;a++){
			nxt[a][lg] = nxt[nxt[a][lg-1]][lg-1];
			mn[a][lg] = min(mn[a][lg-1], mn[nxt[a][lg-1]][lg-1]);
		}
	}
	for(int a=0;a<m;a++){
		ll x;
		int l, r;
		scanf("%lld %d %d", &x, &l, &r);
		l--;
		r--;
		int i = l, lg = LOGN-1;
		while(i <= r){
			lg = LOGN-1;
			while(lg > 0 && i <= r){
				if(nxt[i][lg]-1 <= r && mn[i][lg] > x)
					i = nxt[i][lg];
				lg--;
			}
			if(mn[i][0] > x)
				i = nxt[i][0];
			if(i > r) break;
			x %= s[i];
			i++;
		}
		printf("%lld\n", x);
	}
}

