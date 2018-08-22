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

const int MAXN = 1023;

int n, m, k;
int s[MAXN], mrk[MAXN];

ll cnt[MAXN];

vector<ll> p;

int main (){
	for(ll a=2;a<MAXN;a++){
		if(mrk[a])continue;
		p.pb(a);
		for(ll b=a;a*b<MAXN;b++)
			mrk[a*b] = 1;
	}
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		int val = a;
		for(int ip = 0;ip < p.size();ip++){
			ll pri = p[ip];
			if(pri > val) break;
			while(val%pri == 0 && val != 0){
				val/=pri;
				cnt[ip]++;
			}
			
		}
	}
	ll res = 1;
	for(int a=0;a<p.size();a++){
		res = mod(res *( cnt[a] + 1) );
	}
	printf("%lld\n", res);
}

