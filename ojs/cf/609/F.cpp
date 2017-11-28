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

const int MAXN = 412345;

int n, m, k;
ll s[MAXN], p[MAXN];

vector<ll> X;

map<ll, int> ind;

int up(int i){
	return upper_bound(X.begin(), X.end(), p[a] + s[a]) - X.begin() - 1;
}

int main ()
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &p[a], &s[a]);
		X.pb(p[a]);
	}
	for(int a=0;a<m;a++){
		scanf("%lld%lld", mx+a, ms+a); 
		X.pb(mx[a]);
	}
	sort(X.begin(), X.end());
	erase(unique(X.begin(), X.end()), X.end());
	for(int i=0;i<X.size();i++){
		ind[X[i]] = i;
	}
	for(int a=0;a<n;a++){
		int i = ind[p[a]];
		int j = up(a);
	}
}

