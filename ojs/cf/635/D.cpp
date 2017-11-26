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
int v[3];

ll bit[3][MAXN];

ll qry(int t, int i){
	i += 2;
	i = min(i, MAXN-1);
	ll ans = 0;
	while(i > 0){
		ans += bit[t][i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int t, int i, ll val){
	i += 2;
	while(i < MAXN){
		bit[t][i] += val;
		i += (i&-i);
	}
}

int main (){
	scanf("%d%d%d%d%d", &n, &k, &v[1], &v[0], &m);
	for(int a=0;a<m;a++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int d;
			ll q;
			scanf("%d %lld", &d, &q);
			for(int a=0;a<2;a++){
				ll qtd = qry(a, d) - qry(a, d-1);
				upd(a, d, min(q, v[a] - qtd));
			}
		}
		else{
			int ini;
			scanf("%d", &ini);
			printf("%lld\n", qry(0, ini-1) + qry(1, MAXN - 10) - qry(1, ini+k-1));
		}

	}
}

