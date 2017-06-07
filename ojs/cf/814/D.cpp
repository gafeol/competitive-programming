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
ll res;

struct cc{
	ll x, y;
	ll r;
} s[MAXN];

vector<cc> q[2];

bool cmp(cc a, cc b){
	return a.r > b.r;
}

ll dist(cc a, cc b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool in(cc a, cc b){
	if(b.r > a.r) swap(a, b);

	if(dist(a, b) <= a.r*a.r)
		return true;
	return false;
}

ll put(int i, int t){
	ll ans = s[i].r*s[i].r;
	int cnt = 0;
	for(cc c: q[t]){
		if(in(c, s[i]))
			cnt++;
	}
//	debug("put %d %d cnt %d\n", i, t, cnt);
	if((cnt&1))
		return -ans;
	else
		return ans;
}

double pi = acos(-1.);

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld %lld%lld", &s[a].x, &s[a].y, &s[a].r); 
	}
	sort(s, s+n, cmp);
	for(int a=0;a<n;a++){
		if(put(a, 0) > put(a, 1)){
			q[0].pb(s[a]);
			res += -put(a, 0);
		}
		else{
			q[1].pb(s[a]);
			res += -put(a, 1);
		}
	}
	printf("%.20f\n", res*pi);

}
