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
int s[MAXN][3];
pii v[MAXN];
ll res;

int bit[MAXN];

void upd(int i, int val){
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

int qry(int i){
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void solve(){
	sort(v, v+n);
	for(int a=0;a<n;a++){
		upd(v[a].snd, 1);
	}
	for(int a=0;a<n;a++){
		upd(v[a].snd, -1);
		res += qry(v[a].snd);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d %d", &s[a][0], &s[a][1], &s[a][2]);
	}
	for(int a=0;a<n;a++){
		v[a].fst = s[a][0];
		v[a].snd = s[a][1];
	}
	solve();
	for(int a=0;a<n;a++){
		v[a].fst = s[a][0];
		v[a].snd = s[a][2];
	}
	solve();
	for(int a=0;a<n;a++){
		v[a].fst = s[a][1];
		v[a].snd = s[a][2];
	}
	solve();
	printf("%lld\n", res/2);
}
