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

const int MAXN = 262345;

int n, m, k;
ll s[MAXN], v[MAXN];

int main (){
	srand(time(NULL));
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++){
		v[a] = s[a] = rand();
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);	
		s[i] ^= v[j];
		s[j] ^= v[i];
	}
	for(int a=0;a<k;a++){
		int q;
		scanf("%d", &q);
		vector<int> vs;
		vs.clear();
		ll xo = 0;
		while(q--){
			int x;
			scanf("%d", &x); 
			xo ^= v[x];
			vs.pb(x);
		}
		for(int u: vs){
			s[u] = s[u]^xo^v[u];
		}
	}
	for(int a=1;a<=n;a++){
		if(s[a] == v[a])
			puts("TAK");
		else
			puts("NIE");
	}
}
