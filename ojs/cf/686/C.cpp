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

ll n, m, k, nn, mm, vv;
int dn, dm;


int cas(ll x){
	int cnt = 0;
	ll aux = 0;
	vv=0;
	while(x != 0){
		aux *= 10;
		aux += x%7;
//		debug("bota no aux %lld x %lld\n", x%7, x);
		x/=7;
		cnt++;
	}
//	debug("x %lld %lld\n", x, aux);
	for(int a=0;a<cnt;a++){
		vv*= 10;
		vv += aux%10;
		aux/=10;
	}
	return cnt;
}

int mrk[8];
int ind;

bool dif(ll a, ll b){
	memset(mrk, 0, sizeof(mrk));
	debug("dif %lld %lld\n", a, b);
	for(int i=0;i<dn;i++){
	//	debug("num %lld\n", a%10);
		mrk[a%10]++;
		if(mrk[a%10] > 1)
			return false;
		a/=10;
	}
	for(int i=0;i<dm;i++){
	//	debug("num %lld\n", b%10);
		mrk[b%10]++;
		ind = i;
		if(mrk[b%10] > 1)
			return false;
		b/=10;
	}
	return true;
}

bool rep(ll a, int d){
	memset(mrk, 0, sizeof(mrk));
	for(int i=0;i<d;i++){
	//	debug("num %lld\n", a%10);
		mrk[a%10]++;
		if(mrk[a%10] > 1)
			return true;
		a/=10;
	}
	return false;
}

ll trans(ll x, int c){
	int cnt = c;
	ll aux = 0;
	vv=0;
	for(int a=0;a<cnt;a++){
		aux *= 10;
		aux += x%7;
		//		debug("bota no aux %lld x %lld\n", x%7, x);
		x/=7;
	}
	for(int a=0;a<cnt;a++){
		vv*= 10;
		vv += aux%10;
		aux/=10;
	}
	return vv;
}

ll seti[10];

int main (){
	scanf("%lld%lld", &n, &m);
	if(n != 1)
		dn = cas(n-1);
	nn = vv;
	if(m != 1)
		dm = cas(m-1);
	mm = vv;
	//	printf("%d %lld %d %lld\n", dn, nn, dm, mm);
	if(n == 1){
		dn = 1;
		nn = 0;
	}
	if(m == 1){
		dm = 1;
		mm = 0;
	}

	if(dm + dn > 7){
		puts("0");
		return 0;
	}
	ll res =0;
	seti[0] = 1;
	for(int a=1;a<10;a++){
		seti[a] = seti[a-1]*7ll;
	}
	for(ll a=0;a < n;a++){
		ll aa = trans(a, dn);
		if(!(aa <= nn)) break;
		if(rep(aa, dn)) continue;
		for(ll b=0;b < m;b++){
			ll bb = trans(b, dm); 
			debug("test %lld %lld   %lld %lld\n", a, aa, b, bb);
			if(!(bb <= mm)) break;
			if(rep(bb, dm)) continue;
			ind = -1;
			if(dif(aa, bb)){
				res++;
				debug("INCR %lld %lld\n", aa, bb);
			}
		}
	}

	printf("%lld\n", res);
}
