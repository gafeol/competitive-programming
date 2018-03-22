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
ll s[MAXN];

multiset<ll> q;
ll off;

void add(ll x){
	q.insert(x+off);
}

ll ans;

void rmv(ll val){
	ans = 0;
	while(!q.empty() && (*q.begin() - off - val) <= 0){
		ans += *q.begin() - off;
		q.erase(q.begin());
	}
	ans += q.size()*(val);
	off += val;
	printf("%lld ", ans);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	for(int a=0;a<n;a++){
		ll x;
		scanf("%lld", &x);
		add(s[a]);
		rmv(x);
	}
	puts("");
}

