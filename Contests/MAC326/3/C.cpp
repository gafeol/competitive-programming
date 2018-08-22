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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
pii s[MAXN];

vector<int> ind;


bool go(ll t){
	ll bef = 0;
	for(int ii=0;ii<n;ii++){
		int i = ind[ii];
		if(s[i].snd < bef) return false;
		if(s[i].fst > bef)
			bef = (ll)s[i].fst + t;
		else
			bef = bef + t;
	}
	return true;
}

int main (){
	int t = 1;
	while(scanf("%d", &n) != EOF && n > 0){
		ind.clear();
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			i *= 60000;
			j *= 60000;
			s[a] = pii(i, j);
			ind.pb(a);
		}
		ll res = 0;
		do{
			ll ini = 0, fim = 14400000*6ll;
			while(ini < fim){
				ll mid = (ini+fim+1)/2ll;
				if(go(mid))
					ini = mid;
				else
					fim = mid-1;
			}
			res = max(res, ini);
		} while(next_permutation(ind.begin(), ind.end()));
		debug("res %lld\n", res);
		ll ans = (res + 500)/1000;
		printf("Case %d: %lld:%02lld\n", t++, ans/60, ans%60);
		
	}
}

