#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<double, ll> pdi;
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

pii da[MAXN], db[MAXN];

pii p[3], t, s[MAXN];

ll dist(pii a, pii b){
	return (a.fst - b.fst)*(a.fst - b.fst) + (a.snd - b.snd)*(a.snd - b.snd);
}

double d(pii a, pii b){
	return sqrt(dist(a, b));
}

int main (){
	scanf("%lld %lld %lld %lld %lld %lld", &p[0].fst, &p[0].snd, &p[1].fst, &p[1].snd, &t.fst, &t.snd);
	scanf("%d", &n);
	double sum = 0;
	for(ll a=0;a<n;a++){
		scanf("%lld %lld", &s[a].fst, &s[a].snd);
		da[a] = pdi(d(s[a], p[0]) - d(s[a], t), a);
		db[a] = pdi(d(s[a], p[1]) - d(s[a], t), a);
		sum += 2.*d(s[a], t);
	}
	sort(da, da+n);
	sort(db, db+n);
	double res = 0;
	if(n == 1){
		res = d(s[0], t) + min(d(s[0], p[0]), d(s[0], p[1]));
		printf("%.15f\n", res);
		return 0;
	}
	res = sum - d(s[da[0].snd], t) + d(s[da[0].snd], p[0]);
	res = min(res, sum - d(s[db[0].snd], t) + d(s[db[0].snd], p[1]));
	if(da[0].snd != db[0].snd)
		res = min(res, sum - d(s[da[0].snd], t) + d(s[da[0].snd], p[0]) - d(s[db[0].snd], t) + d(s[db[0].snd], p[1]));
	if(da[0].snd != db[1].snd)
		res = min(res, sum - d(s[da[0].snd], t) + d(s[da[0].snd], p[0]) - d(s[db[1].snd], t) + d(s[db[1].snd], p[1]));
	if(da[1].snd != db[0].snd)
		res = min(res, sum - d(s[da[1].snd], t) + d(s[da[1].snd], p[0]) - d(s[db[0].snd], t) + d(s[db[0].snd], p[1]));
	for(int i=0;i<n;i++){
		res = min(res, sum + d(p[1], s[i]) - d(s[i], t));
		res = min(res, sum + d(p[0], s[i]) - d(s[i], t));
		if(i == da[0].snd)
			res = min(res, sum + d(p[1], s[i]) - d(s[i], t) + d(s[da[1].snd], p[0]) - d(s[da[1].snd], t));
		else
			res = min(res, sum + d(p[1], s[i]) - d(s[i], t) + d(s[da[0].snd], p[0]) - d(s[da[0].snd], t));
		if(i == db[0].snd)
			res = min(res, sum + d(p[0], s[i]) - d(s[i], t) + d(s[db[1].snd], p[1]) - d(s[db[1].snd], t));
		else
			res = min(res, sum + d(p[0], s[i]) - d(s[i], t) + d(s[db[0].snd], p[1]) - d(s[db[0].snd], t));
	}
	printf("%.15f\n", res);
}
