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

const int MAXN = 212345, INF = 1e8;

int n, m, k;
int s[MAXN], bit[MAXN];

void upd(int i){
	while(i <= n){
		bit[i]++;
		i += (i&-i);
	}
}

int qry(int i){
	if(i > n) return INF;
	debug("qry %d: ", i);
	int res = 0;
	while(i > 0){
		res += bit[i];
		i -= (i&-i);
	}
	debug("%d\n", res);
	return res;
}

int main (){
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &m);
	for(int a=0;a<m;a++){
		scanf("%d", &s[a]);
		upd(s[a]);
	}
	int res = min(k, qry(k));
	for(int a=0;a<m;a++){
		res = min(res, qry(s[a]+k)-qry(s[a]));
	}
	printf("%d\n", res);
}
