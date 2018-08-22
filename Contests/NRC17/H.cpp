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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

ll T, n;
int m;

vector<pll> s;


void fodeu(){
	puts("No");
	exit(0);
}

ll PA(ll x, ll y){
	debug("PA %lld %lld: %lld\n", x, y, ((x + y)*(abs(x - y) + 1))/2ll);
	return ((x + y)*(abs(x - y) + 1))/2ll;
}

ll mnh(int i, int j){
	ll hi = s[i].snd;
	ll hj = s[j].snd;
	ll pi = s[i].fst;
	ll pj = s[j].fst;

	ll sum = hi - hj + pi + pj;

	ll x = sum/2;

	debug("x mn %lld\n", x); 

	ll ans = 0;

	if((sum&1)){
		ll mny = max(0ll, hi -x + pi);

		ans += PA(hi, mny);
		ans += PA(mny, hj);
	}
	else{
		ll mny = max(0ll, hi - x + pi); 
		ans += PA(hi, mny);
		ans += PA(mny, hj);
		ans -= mny;
		debug("ans -= %lld\n", mny);
	}
	return ans;
}

ll mxh(int i, int j){
	ll hi = s[i].snd;
	ll hj = s[j].snd;
	ll pi = s[i].fst;
	ll pj = s[j].fst;

	ll sum = hj - hi + pi + pj;

	ll x = sum/2;
	debug("x mx %lld\n", x); 

	ll ans = 0;

	if((sum&1)){
		ll mxy = hi + x - pi;
		debug("mxy = %lld\n", mxy);
		ans += PA(hi, mxy);
		ans += PA(mxy, hj);
	}
	else{
		ll mxy = hj - x + pj; 
		debug("hj %lld - x %lld - 1 + pi %lld \nmxy = %lld\n",hj, x, pj, mxy);
		ans += PA(hi, mxy);
		ans += PA(mxy, hj);
		ans -= mxy;
		debug("ans -= %lld\n", mxy);
	}
	return ans;
}

int main (){
	scanf("%lld %lld %d",&T, &n, &m);
	for(int a=0;a<m;a++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		s.pb(pll(x, y));
	}
	ll mn = 0, mx = 0;
	for(int i=1;i<s.size();i++){
		ll dx = s[i].fst - s[i-1].fst - 1;
		if(abs(s[i].snd - s[i-1].snd) -1 > dx) fodeu();
		mn += mnh(i-1, i);	
		mx += mxh(i-1, i);
		mn -= s[i-1].snd;
		mx -= s[i-1].snd;
	}
	ll iniy = max(0ll, s[0].snd - s[0].fst + 1);
	mn += PA(iniy, s[0].snd);
	ll fimy = max(0ll, s[m-1].snd - (n - s[m-1].fst));
	mn += PA(s[m-1].snd, fimy);
	mn -= s[m-1].snd; 

	iniy = s[0].snd + s[0].fst - 1;
	mx += PA(iniy, s[0].snd);
	fimy = s[m-1].snd + (n - s[m-1].fst);
	mx += PA(s[m-1].snd, fimy);
	mx -= s[m-1].snd; 


	debug("mn %lld mx %lld\n", mn, mx);

	if(T >= mn && T <= mx)
		puts("Yes");
	else
		puts("No");
}

