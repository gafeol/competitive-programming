#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

const int N = 2e3;

int n, k;
int x[N], m[N], p[N], st[N];

ll solve(int l, int r){
	sort(p+l,p+r,[&](int i, int j){ return abs(x[i]) < abs(x[j]); });
	ll ans = 0; int ss = 0;
	for(int i=l;i<r;i++) st[ss++] = p[i];
	while(ss > 0){
		int i = st[--ss];
		int t = (m[i] + k - 1)/k;

		ans += ll(2*t)*ll(abs(x[i]));

		int bonus = t*k - m[i];
		while(bonus > 0){
			while(ss > 0 && m[st[ss-1]] == 0) ss--;
			if(ss > 0){
				int d = min(bonus, m[st[ss-1]]);
				m[st[ss-1]] -= d;
				bonus       -= d;
			} else bonus = 0;
		}
	}
	return ans;
}

int main (){
	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		scanf(" %d%d", x+i, m+i);
		p[i] = i;
	}
	sort(p,p+n,[&](int i, int j){ return x[i] < x[j]; });
	int m = 0;
	while(x[p[m]] < 0) m++;
	ll ans = solve(0,m);

	while(x[p[m]] == 0) m++;
	ans += solve(m,n);

	printf("%lld\n", ans);
}

