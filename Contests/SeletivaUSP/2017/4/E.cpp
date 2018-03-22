#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, int> ppi;
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
ll d;
int deg = 0;

pll p[2];

map<ll, vector<ppi> > ev;

ppi mk(ll a, ll b, int c){
	return ppi(pll(a, b), c);
}

pll trans(ll x, ll y){
	return pll(x + y, x - y);
}

pll untrans(pll u){
	return pll((u.fst + u.snd)/2, (u.fst - u.snd)/2);
}

void add(ll x, ll y){
	pll i = trans(x, y-d);
	pll ii = trans(x-d, y);
	debug("i (%lld %lld)\n", i.fst, i.snd);
	debug("ii (%lld %lld)\n", ii.fst, ii.snd);
	ev[i.fst].pb(mk(ii.snd, i.snd, 1));	
	pll j = trans(x+d, y);
	pll jj = trans(x, y+d);
	debug("j (%lld %lld)\n", j.fst, j.snd);
	debug("jj (%lld %lld)\n", jj.fst, jj.snd);
	ev[j.fst+1].pb(mk(jj.snd, j.snd, -1));
}

void go(){
	ll i = LLONG_MIN, j = LLONG_MAX;
	int cnt = 0, ult = 0;
	vector<ppi> v;
	for(auto& it: ev){
		ult = cnt;
		ll x = it.fst;
		v = it.snd;
		debug("line sweep x %lld cnt %d\n", x, cnt);
		for(ppi e: v){
			debug("	ev tipo %d de %lld - %lld\n", e.snd, e.fst.fst, e.fst.snd);
			cnt += e.snd;
			i = max(i, e.fst.fst);
			j = min(j, e.fst.snd);
		}
		debug("line sweep x %lld cnt %d\n", x, cnt);
		if(cnt == n){
			p[0] = pll(x, i);
			deg++;
		}
		else if(ult == n){
			p[1] = pll(x-1, j);
			deg++;
		}
	}
}

vector<ll> X, Y;
vector<ll> X2, Y2;

ll rx, ry;
ll res = LLONG_MAX;

ll test(ll x, ll y){
	assert(!((x + y)&1));
	ll xx = x;
	ll yy = y;
	x = untrans(pll(xx, yy)).fst;
	y = untrans(pll(xx, yy)).snd;
	ll ans = 0;
	for(int a=0;a<n;a++){
		ans += abs(s[a].fst - x) + abs(s[a].snd - y);
	}
	if(ans < res){
		res = ans;
		rx = x;
		ry = y;
	}
	return ans;
}

void btx(ll x, ll y, ll yy){
	ll i = y, j = yy;
	if((x + y)&1)
		i++;
	if((x + yy)&1)
		j--;
	if(i > j) return ;
	while((j + 1 - i)/2 > 3){
		ll h = (j + 1 - i)/2;
		ll mi = i + (h/3)*2;
		ll mj = j - (h/3)*2;
		if(test(x, mi) < test(x, mj))
			j = mj;
		else
			i = mi;
	}
	for(int a=i;a<=j;a++){
		if((x + a)%2 == 0)
			test(x, a);
	}
}

void bty(ll y, ll x, ll xx){
	ll i = x, j = xx;
	if((y + x)&1)
		i++;
	if((y + xx)&1)
		j--;
	if(i > j) return ;
	while((j + 1 - i)/2 > 3){
		ll h = (j + 1 - i)/2;
		ll mi = i + (h/3)*2;
		ll mj = j - (h/3)*2;
		if(test(mi, y) < test(mj, y))
			j = mj;
		else
			i = mi;
	}
	for(int a=i;a<=j;a++){
		if((y + a)%2 == 0)
			test(a, y);
	}
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a].fst, &s[a].snd);
		X2.pb(s[a].fst);
		Y2.pb(s[a].snd);
		//debug("(%lld %lld) -> (%lld %lld)\n", s[a].fst, s[a].snd, trans(s[a].fst, s[a].snd).fst, trans(s[a].fst, s[a].snd).snd);
	}
	sort(X2.begin(), X2.end());
	sort(Y2.begin(), Y2.end());
	scanf("%lld", &d);
	for(int a=0;a<n;a++)
		add(s[a].fst, s[a].snd);

	go();
	//debug("(%lld %lld) (%lld %lld)\n", p[0].fst, p[0].snd, p[1].fst, p[1].snd);
	if(deg < 2 || p[0].snd > p[1].snd || p[0].fst > p[1].fst){
		puts("impossible");
		return 0;
	}
	ll mx2 = X2[n/2];
	ll my2 = Y2[n/2];
	ll mx = trans(mx2, my2).fst;
	ll my = trans(mx2, my2).snd;
//	debug("mx my (%lld %lld)\n", mx, my);
//	debug("mx my (%lld %lld)\n", trans(mx2, my2).fst, trans(mx2, my2).snd);

	pll lb = p[0];
	pll ru = p[1];

	if(mx >= lb.fst && mx <= ru.fst && my >= lb.snd && my <= ru.snd)
		test(mx, my);
		
	/*debug("a\n");
	test(p[0].fst, p[0].snd);
	debug("a\n");
	test(p[0].fst, p[1].snd);
	debug("a\n");
	test(p[1].fst, p[0].snd);
	debug("a\n");
	test(p[1].fst, p[1].snd);
	debug("a\n");
	test(rx, p[0].snd);
	debug("a\n");
	test(rx, p[1].snd);
	debug("a\n");
	test(p[0].fst, ry);
	debug("a\n");
	test(p[1].fst, ry);
	debug("%lld\n", res);
*/
	btx(p[0].fst, p[0].snd, p[1].snd);
	btx(p[1].fst, p[0].snd, p[1].snd);
//	debug("%lld\n", res);
	bty(p[0].snd, p[0].fst, p[1].fst);
	bty(p[1].snd, p[0].fst, p[1].fst);
	if(res == LLONG_MAX)
		puts("impossible");
	else
		printf("%lld\n", res);
}
