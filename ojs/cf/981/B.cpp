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

map<int,int> c;
vector<int> v;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d%d", s+a, &x);
		v.pb(s[a]);
		c[s[a]] = x;
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int x;
		scanf("%d %d", s+a, &x);
		v.pb(s[a]);
		c[s[a]] = max(x, c[s[a]]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ll res = 0;
	for(int i=0;i<v.size();i++){
		int val = v[i];
		res += (ll)c[val];
	}
	printf("%lld\n", res);
}

