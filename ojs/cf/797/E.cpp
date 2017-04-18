#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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

int m;
ll n;
ll s[MAXN], res[MAXN];
int mrk[MAXN], tempo[MAXN];

int go(int i, int k){
	int ans = 0;
	if(i > n) return 0;
	if(tempo[i] != k){
		tempo[i] = k;
		mrk[i] = -1;
	}
	if(mrk[i] != -1)
		return mrk[i];
	return mrk[i] = 1 + go(s[i] + k + i, k);		
}

struct qr{
	int p, k, i;
	qr(){}
	qr(int pp, int kk, int ii){
		p = pp;
		k = kk;
		i = ii;
	}
	bool operator < (qr o){
		return k < o.k;
	}
} qry[MAXN];

int main (){
	scanf("%lld", &n);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		ll p, k;
		scanf("%lld %lld", &p, &k);
		qry[a] = qr(p, k, a);
	}
	sort(qry, qry+m);
	for(int a=0;a<m;a++){
		res[qry[a].i] = go(qry[a].p, qry[a].k);
	}
	for(int a=0;a<m;a++){
		printf("%lld\n", res[a]);
	}
}
