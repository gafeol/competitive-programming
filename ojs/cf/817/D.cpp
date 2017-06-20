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
int s[MAXN];
int mx[MAXN][2];
int mn[MAXN][2];

set<int> pos;

vector<pii> ind;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		ind.pb(pii(s[a], a));
	}

	sort(ind.begin(), ind.end());

	for(int a=1;a<n;a++){
		if(s[a-1] > s[a])
			mx[a][0] = a-1;
		else
				
	}
	for(int a=n-2;a>=0;a--){
	}
	ll res = 0;
	for(int a=0;a<n;a++){
		int l = mx[a][0];
		if(l == a)
			l = -1;
		int r = mx[a][1];
		if(r == a)
			r = n;
		res += s[a]*(a - l)*(r - a);
		debug("soma l %d r %d res += %d\n", l, r, s[a]*(a - l)*(r - a));

		l = mn[a][0];
		if(l == a)
			l = -1;
		r = mn[a][1];
		if(r == a)
			r = n;
		res -= s[a]*(a - l)*(r - a);
		debug("sub l %d r %d res -= %d\n", l, r, s[a]*(a - l)*(r - a));
	}
	printf("%lld\n", res);

}
