#include <bits/stdc++.h>

using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
pll s[MAXN];

ll mdc(ll a, ll b){
	if(b == 0) return a;
	return mdc(b, a%b);
}

pll operator -(pll u, pll o){
	return pll(u.fst - o.fst, u.snd - o.snd);
}
ll operator ^(pll u, pll o){
	return u.fst*o.snd - u.snd*o.fst;
}

ll cross(pll a, pll b, pll c){
	return (b - a)^(c - a);
}


bool check(int i, int j){
	vector<int> nin;
	for(int a=0;a<n;a++){
		if(cross(s[i], s[j], s[a]) != 0){
			nin.pb(a);
		}
	}
	if(nin.size() < 3)
		return true;

	ll dx = s[nin[0]].fst - s[nin[1]].fst;
	ll dy = s[nin[0]].snd - s[nin[1]].snd;
	ll md = mdc(abs(dx), abs(dy));
	dx/= md;
	dy/= md;
	for(int a=2;a<nin.size();a++){
		ll xx = s[nin[a]].fst - s[nin[1]].fst;
		ll yy = s[nin[a]].snd - s[nin[1]].snd;
		md = mdc(abs(xx), abs(yy));
		xx/=md;
		yy/=md;
		if((dx != xx || dy != yy) && (dx != -1ll*xx || dy != -1ll*yy))
			return false;
	}
	return true;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%lld %lld", &s[a].fst, &s[a].snd);
	if(n <= 2){
		printf("YES\n");
		return 0;
	}
	if(check(0, 1) || check(0, 2) || check(1, 2))
		puts("YES");
	else
		puts("NO");
}

