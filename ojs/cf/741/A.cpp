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
int s[MAXN];
int mrk[MAXN];
int cyc, sz;

void go(int v, int ini){
	mrk[v] = 1;
	sz++;
	if(mrk[s[v]] && s[v] != ini)
		cyc = 0;
	else if(mrk[s[v]])
		return;
	else
		go(s[v], ini);
}

vector<int> v;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll mmc(ll a, ll b){
	return (a*b)/gcd(a, b);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	cyc = 1;
	for(int a=1;a<=n;a++){
		if(mrk[a]) continue; 
		sz = 0;
		go(a, a);
		v.pb(sz);
	}
	if(!cyc)
		puts("-1");
	else{
		ll res = v[0];
		for(int i=1;i<v.size();i++){
			res = mmc(res, v[i]); 
		}
		if(!(res&1)) res >>=1;
		printf("%lld\n", res);
	}
}
