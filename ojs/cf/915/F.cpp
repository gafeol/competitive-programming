#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

int pai[MAXN];
int sz[MAXN];

vector<ppi> ar, in;

void mk(int i, int j){
	ar.pb(ppi(pii(i, j), max(s[i], s[j])));
	in.pb(ppi(pii(i, j), min(s[i], s[j])));
}

bool cmp(ppi a, ppi b){
	return a.snd < b.snd;
}

bool cmp2(ppi a, ppi b){
	return a.snd > b.snd;
}

void join(int i, int j){
	if(sz[i] > sz[j])
		swap(i, j);
	sz[j] += sz[i];
	pai[i] = j;
}

int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", s+a);
		pai[a] = a;
		sz[a] = 1;
	}
	ll res =0;
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		mk(i, j);
	}
	sort(ar.begin(), ar.end(), cmp);
	for(ppi ares: ar){
		int i = ares.fst.fst;
		int j = ares.fst.snd;
		ll  v = ares.snd;
		i = raiz(i);
		j = raiz(j);
		res += (ll(sz[i])*(ll)sz[j])*v;
		join(i, j);
	}

	for(int a=1;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
	}

	sort(in.begin(), in.end(), cmp2);
	for(ppi ares: in){
		int i = ares.fst.fst;
		int j = ares.fst.snd;
		ll  v = ares.snd;
		i = raiz(i);
		j = raiz(j);
		res -= (ll(sz[i])*(ll)sz[j])*v;
		join(i, j);
	}
	printf("%lld\n", res);
}

