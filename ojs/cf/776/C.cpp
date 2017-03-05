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

int n, m;
ll k;
ll s[MAXN];
ll sum[MAXN];

vector<ll> p;

map<ll, ll> mrk;

int main (){
	scanf("%d%lld", &n, &k);
	ll kk = k;
	p.pb(1);
	int cnt = 0;
	while(abs(k) <= 1e14){
		if(kk == 1) break;
		if(kk == -1){
			p.pb(-1);
			break;
		}
		p.pb(k);
		k *= kk;
		cnt++;
	}
	debug("cnt %d\n", cnt);
	ll res = 0;
	mrk[0]++;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		if(a != 0)
			sum[a] = sum[a-1];
		sum[a] += s[a];
		for(ll pot: p){
			if(mrk.find(sum[a] - pot) != mrk.end())
				res += mrk[sum[a] - pot];
		}
		mrk[sum[a]]++;
	}

	printf("%lld\n", res);
}
