#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }

const int MAXN = 212345;

ll modn = 1000000007;
int n, m, k;
int s[MAXN], sp[MAXN][30];
int mrk[MAXN];

vector<int> p;
inline ll mod(ll x) { return x % modn; }

ll expo(ll base, ll e){
	ll res = mod(1);
	while(e > 0){
		if(e&1)
			res = mod(res*base);
		base = mod(base*base);
		e >>= 1;
	}
	return res;
}

int main (){
	for(int a=2;a<=100;a++){
		if(mrk[a]==0){
			p.pb(a);
			for(int b=a;b*a<=100;b++){
				mrk[b*a] = 1;
			}
		}
	}
	int np = p.size();
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		for(int b=0;b<np;b++){
			sp[a][b] = sp[a-1][b];
			while(s[a] != 0 && s[a]%p[b] == 0){
				s[a] /= p[b];
				sp[a][b]++;
			}
		}
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		ll ans = 1;
		int l, r;
		scanf("%d%d%lld", &l, &r, &modn);
		for(int b=0;b<np;b++){
			ll e = sp[r][b] - sp[l-1][b];
			ans = mod(ans*expo(p[b], e));
		}
		printf("%lld\n", ans);	
	}
}
