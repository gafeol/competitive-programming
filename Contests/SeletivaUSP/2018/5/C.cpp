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

const int MAXN = 1000006;

int n, m, k;
int s[MAXN];

ll p[MAXN], sz[MAXN];
ll A, B;

int res = 0;

ll _raiz(ll i){
	if(p[i] == i) return i;
	return p[i] = _raiz(p[i]);
}

ll raiz(ll i){
	return _raiz(i-A);
}


void join(ll i, ll j){

	i = raiz(i);
	j = raiz(j);

	if(i == j) return ;
	
	res++;

	if(sz[i] < sz[j])
		swap(i, j);
	sz[i] += sz[j];
	p[j] = i;
}

int mrk[MAXN];
vector<ll> pri;

int main (){
	for(ll a = 2;a<=MAXN;a++){
		if(mrk[a]) continue;
		pri.pb(a);
		for(ll b = a; a * b <= MAXN;b++){
			mrk[a*b] = 1;	
		}
	}
	for_tests(t, tt){
		res = 0;
		ll P;
		scanf("%lld%lld%lld", &A, &B, &P);
		for(ll a = A;a <= B;a++){
			p[a - A] = a-A;
			sz[a-A] = 1;
		}
		for(ll p: pri){
			if(p < P) continue;
			ll ult = -1;
			for(ll mult = (A+p-1)/p; mult * p <= B;mult++){
				if(ult != -1)
					join(ult, mult*p);
				ult = mult*p;
			}
		}
		printf("Case #%d: %lld\n", tt, (B - A + 1 - res));
	}
}

