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

const int MAXN = 112345;

int n, m, k;
int s[MAXN], bit[MAXN], ind[MAXN], res;

int qry(int i){
	i+=2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i){
	i += 2;
	while(i < MAXN){
		bit[i]++;
		i += (i&-i);
	}
}

bool cmp(int a, int b){
	return s[a] >  s[b];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		ind[a] = a;
		res += s[a];
	}
	sort(ind, ind+n, cmp);
	for(int a=0;a<n;a++){
		debug("a %d ind[a] %d qry %d + 1\n", a, ind[a], qry(ind[a]));
		if((ind[a] - qry(ind[a]) + 1) > m){
			debug("pega %d %d\n", ind[a], s[ind[a]]);
			upd(ind[a]);
			res -= s[ind[a]];
		}
	}
	printf("%d\n", res);
}

