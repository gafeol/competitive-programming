#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;

#define int ll 

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
pii s[MAXN];
int d[MAXN][2];

bool cmp(int a, int b){
	return d[a][0] < d[b][0];
}

bool cmp2(int a, int b){
	return d[a][1] < d[b][1];
}

vector<ll> q[2][2];
ll h;

ll qry(int d, int t, int l, int r){
	if(l > r) swap(l, r);
	if(lower_bound(q[d][t].begin(), q[d][t].end(), l) == q[d][t].end()) return 0;
	return ((--upper_bound(q[d][t].begin(), q[d][t].end(), r)) - (lower_bound(q[d][t].begin(), q[d][t].end(), l)));
}


main (){
	scanf("%lld%lld", &n, &h);
	for(int a=0;a<n;a++){
		scanf("%lld %lld", &s[a].fst, &s[a].snd);	
		d[a][0] = h-1 - s[a].snd + s[a].fst;
		d[a][1] = s[a].fst - s[a].snd;
		debug("adj %lld %lld\n", d[a][0], d[a][1]);
		int t = ((s[a].fst + s[a].snd)&1);
		q[0][t].pb((s[a].fst - s[a].snd));
		q[1][t].pb((s[a].fst + s[a].snd));
	}
	ll res = 0;
	for(int a=0;a<n;a++){
		res += 2*h - 2 - qry(0, ((s[a].fst+s[a].snd)&1), d[a][1], d[a][0] + h-1)  - qry(1, ((s[a].fst+s[a].snd)&1), d[a][0], d[a][1] - h+1); 
	}
	printf("%lld\n", res);
}

