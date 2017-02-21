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
pii s[MAXN];

int main (){
	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
	}
	sort(s, s+n);
	ll t = 0;
	for(int a=0;a<n;a++){
		t = max(t, (ll)s[a].fst);
		t += (ll)s[a].snd;
	}
	printf("%lld\n", t);
}
