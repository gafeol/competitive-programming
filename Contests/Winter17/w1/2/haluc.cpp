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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1123456;

int n, m, k;

map<ll, ll> d[2], rd[2];

map<ll, ll> lin[2], rev[2];

void sweep(int t){
	ll ult = -2000000000ll;
	ll carry = 0;
	d[t][ult] = 0;
	for(auto &it: lin[t]){
		ll i = it.fst;
		ll qtd = it.snd;
		debug("to em t %d i %lld qtd %lld\n", t, i, qtd);
		d[t][i] = d[t][ult] + carry*(i - ult);
		debug("d[%d][%lld] = %lld + %lld = %lld\n", t, i, d[t][ult], carry*(i-ult), d[t][i]);
		carry += qtd;
		ult = i;
	}
}

void rsweep(int t){
	ll ult = 2000000000ll;
	ll carry = 0;
	rd[t][-ult] = 0;
	for(auto &it: rev[t]){
		ll i = -it.fst;
		ll qtd = it.snd;
		debug("REV to em t %d i %lld qtd %lld\n", t, i, qtd);
		rd[t][-i] = rd[t][-ult] + carry*(ult - i);
		debug("REV rd[%d][%lld] = %lld + %lld = %lld\n", t, -i, rd[t][-ult], carry*(ult-i), rd[t][-i]);
		carry += qtd;
		ult = i;
	}
}

struct rect{
	ll x, xx, y, yy;
	rect(){}
	rect(int a, int aa, int b, int bb){
		x = a;
		y = aa;
		xx = b;
		yy = bb;
	}
} s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll x, xx, y, yy;
		scanf("%lld%lld%lld%lld", &x, &y, &xx, &yy);
		if(y > yy)
			swap(y, yy);
		if(x > xx)
			swap(x, xx);
		s[a] = rect(x, y, xx, yy);
		for(ll i=y;i<=yy;i++){
			lin[0][i] += xx - x + 1;	
			rev[0][-i] += xx - x + 1;
			debug("lin %lld = %lld\n", i, lin[0][i]);
		}
		for(ll j=x;j<=xx;j++){
			lin[1][j] += yy - y + 1;
			rev[1][-j] += yy - y + 1;
			debug("col %lld = %lld\n", j, lin[1][j]);
		}
	}
	sweep(0);
	rsweep(0);
	sweep(1);
	rsweep(1);

	ll res = LLONG_MAX;
	for(int a=0;a<n;a++){
		int x = s[a].x, xx = s[a].xx, y = s[a].y, yy = s[a].yy;
		for(int i = y;i <= yy;i++){
			for(int j=x;j<=xx;j++){
				res = min(res, d[0][i] + d[1][j] + rd[0][-i] + rd[1][-j]);
			}
		}
	}

	ll rx = LLONG_MAX, ry = LLONG_MAX;
	
	for(int a=0;a<n;a++){
		int x = s[a].x, xx = s[a].xx, y = s[a].y, yy = s[a].yy;
		for(int i = y;i <= yy;i++){
			for(int j=x;j<=xx;j++){
				if(res == d[0][i] + d[1][j] + rd[0][-i] + rd[1][-j]){
					if(j < rx || (j == rx && i < ry)){
						rx = j;
						ry = i;
					}
				}
			}
		}
	}
	printf("%lld\n", res);
	printf("%lld %lld\n", rx, ry);
}
