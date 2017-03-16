#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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

const int MAXN = 71234;

int n, m, k;
int gen[MAXN], res[MAXN];

vector<pll> s[MAXN*4];

vector<ll> cm;
unordered_map<ll, int> ind, mrk;

pll d[MAXN];

set<pii> q;

int main (){
	for_tests(t, tt){
		q.clear();
		ind.clear();
		cm.clear();
		mrk.clear();
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			int p;
			ll i, j;
			scanf("%d %lld %lld", &p, &i, &j);
			i *= 2ll;
			j *= 2ll;
			j++;
			d[a] = pii(i, j);
			if(mrk.find(i) == mrk.end()){
				cm.pb(i);
				mrk[i] = 1;
			}
			if(mrk.find(j) == mrk.end()){
				cm.pb(j);
				mrk[j] = 1;
			}
			if(p != -1) gen[a] = gen[p]+1;

		}
		sort(cm.begin(), cm.end());
		for(int a=0;a<cm.size();a++){
			ind[cm[a]] = a;
		}
		for(int a=0;a<n;a++){
			//	assert(ind.find(d[a].fst) != ind.end());
			//	assert(ind.find(d[a].snd) != ind.end());
			s[ind[d[a].fst]].pb(pii(a, 0));
			s[ind[d[a].snd]].pb(pii(a, 1));
		}
		//s fst-a snd-t
		for(int a=0;a<cm.size();a++){
				
		}
		for(int a=0;a<MAXN*4;a++)
			s[a].clear();
		for(int a=0;a<n;a++){
			if(a != n-1)
				printf("%d ", res[a]);
			else
				printf("%d", res[a]);
			assert(res[a] >= 0);
		}
		if(tt != t)
			printf("\n");
	}
}
