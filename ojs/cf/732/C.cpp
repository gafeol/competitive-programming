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

ll n, m, k;
ll res = LLONG_MAX;
int s[MAXN], v[MAXN];
ll nn, mm, kk;

void botai(int a){
	if(a == 3)
		return;
	kk++;
	if(a == 2)
		return;
	mm++;
	if(a == 1)
		return;
	nn++;
}

void botaf(int a){
	if(a == 0)
		return;
	nn++;
	if(a == 1)
		return;
	mm++;
	if(a == 2)
		return;
	kk++;

}

void testa(ll dn, ll dm, ll dk){
	ll per = (dn < 0ll) + (dm < 0ll) + (dk < 0ll);
	dn = max(dn, 0ll);
	dm = max(dm, 0ll);
	dk = max(dk, 0ll);
	ll mx = max(max(dn, dm), dk);
	//printf("dn %lld dm %lld dk %lld\n", dn, dm, dk);
	//printf("res min(%lld, %lld + %lld)\n",res, per, 3ll*mx-dn-dm-dk);
	res = min(res, per + 3ll*mx-dn-dm-dk); 

}

int main (){
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int a=0;a<4;a++){
		s[a] = a;
		v[a] = a;
	}
	if(max(max(n, m), k) < 2){
		res = 0;
		printf("%lld\n", res);
		return 0;
	}
	for(int a=0;a<4;a++){
		for(int b=0;b<4;b++){
			nn = mm = kk = 0;
			botai(s[a]);
			botaf(v[b]);
	//		printf("testando %d %d\n", s[a], v[b]);
			testa(n - nn, m - mm, k - kk);
		}
	}


	printf("%lld\n", res);
}
