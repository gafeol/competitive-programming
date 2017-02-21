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

const int MAXN = 212;

int n, m, k;
pii s[MAXN*MAXN];
int sz;
vector<int> res;

map<pii, map<pii, int> > mrk;
map<pii, int> vis, M;

int vi[] = {0, 0, 1, -1};
int vj[] = {1, -1, 0, 0};

bool valid(pii x){
	return (x.fst >= 1 && x.fst <= n && x.snd > 0 && x.snd<=n);
}

void go(pii x){
	debug("go %d %d\n", x.fst, x.snd);
	vis[x] = 1;
	if(M.find(x) != M.end())
		sz++;
	for(int a=0;a<4;a++){
		pii nxt = pii(x.fst + vi[a], x.snd + vj[a]);
		if(!valid(nxt)) continue;
		if(mrk.find(x) != mrk.end() && mrk[x].find(nxt) != mrk[x].end()) continue;
		if(vis.find(nxt) != vis.end()) continue;
		go(nxt);
	}
}

int main (){
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &m);
	for(int a=0;a<m;a++){
		int i, j, ii, jj;
		scanf("%d %d %d %d", &i, &j, &ii, &jj);
		mrk[pii(i, j)][pii(ii, jj)] = 1;
		mrk[pii(ii, jj)][pii(i, j)] = 1;
	}
	for(int a=0;a<k;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
		M[s[a]] = 1;
	}
	for(int a=0;a<k;a++){
		if(vis.find(s[a]) == vis.end()){
			sz = 0;
			go(s[a]);
			res.pb(sz);
		}
	}
	ll sum = k;
	ll ans = 0;
	for(int tam: res){
		sum -= tam;
		ans += sum*tam;
	}
	printf("%lld\n", ans);
}
