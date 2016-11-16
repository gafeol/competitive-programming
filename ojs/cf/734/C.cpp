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

int m, k;
ll n;
int s[MAXN];
ll c[MAXN];
ll ma[MAXN];
ll q[MAXN];
ll mb[MAXN];

ll x, mn;
int ind[MAXN];

bool cmp(int a, int b){
	return ma[a] > ma[b];
}

int main (){
	scanf("%lld%d%d", &n, &m, &k);
	scanf("%lld %lld", &x, &mn);
	for(int a=1;a<=m;a++){
		ind[a] = a;
		scanf("%lld", &c[a]);
	}
	for(int a=1;a<=m;a++){
		scanf("%lld", &ma[a]);
	}
	ma[0] = 0;
	c[0] = x;

	sort(ind, ind+m+1, cmp);
	for(int a=1;a<=k;a++){
		scanf("%lld", &q[a]);
	}
	for(int a=1;a<=k;a++){
		scanf("%lld", &mb[a]);
	}
	int j = 0;
	ll res = LLONG_MAX;
	for(int a=0;a<=m;a++){
		int aa = ind[a];
		if(mn - ma[aa] -mb[j] < 0) continue;
		while(j < k && mn - ma[aa] - mb[j+1] >= 0){
			j++;
		}
		res = min(res, (n-q[j])*c[aa]);
	}
	printf("%lld\n", res);
}
