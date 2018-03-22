
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

const int MAXN = 212;

ll n, m, k;
ll q[MAXN], sz[MAXN];
ll acu[MAXN];
ll s[MAXN];

ll d[MAXN], dacu;

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<k;a++){
		scanf("%lld", &q[a]); 
		q[a]--;
	}
	for(int a=0;a<m;a++){
		scanf("%lld", &sz[a]);
	}
	dacu = 0;

	int ok = 1;

	ll som = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &d[a]);
		for(int b=0;b<k;b++){
			ll x;
			scanf("%lld", &x);
			acu[q[b]] += x;
			s[q[b]]+=x;
			som += x;
		}

		d[a] = min(d[a], som - dacu);
		assert(d[a] >= 0);

		ll sob = 0;
		for(int i=0;i<m;i++){
			if(s[i] > sz[i]) ok = 0;
			s[i] = 0;
			if(acu[i] > sz[i]){
				dacu -= (acu[i] - sz[i]);
				som -= (acu[i] - sz[i]);
				acu[i] = sz[i];
				debug("i %d dacu %lld\n", i, dacu);
			}
		}
		if(dacu < 0)
			ok = 0;

		dacu += d[a];
	}
	debug("som %lld\n", som);
	if(som > dacu) ok = 0;
	if(ok)
		puts("possible");
	else
		puts("impossible");
}

