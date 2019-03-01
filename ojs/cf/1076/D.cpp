#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

const int MAXN = 312345;
const ll INF = 10000000000000000LL;

int n, m, k;
int s[MAXN];

ll d[MAXN];
vector<tuple<int, int, int> > adj[MAXN];

bool mrk[MAXN];

vector<int>  ans;

void go(int u){
	mrk[u] = 1;
	for(tuple<int, int, int> tp: adj[u]){
		int nxt, cus, id;
		tie(nxt, cus, id) = tp;

		if(mrk[nxt] || d[nxt] != d[u] + cus) continue;

		if(ans.size() < k)
			ans.pb(id);
		go(nxt);
	}
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		adj[i].pb({j, c, a});
		adj[j].pb({i, c, a});
	}


	for(int a=0;a<=n;a++){
		d[a] = INF;
	}
	set<pli> q;
	d[1] = 0;
	q.insert({0, 1});
	while(!q.empty()){
		pli top = *q.begin();
		q.erase(q.begin());

		int u = top.snd;
		for(tuple<int, int, int> ar: adj[u]){
			int nxt, cus, id;
			tie(nxt, cus, id) = ar;
			if(d[nxt] > d[u] + cus){
				if(d[nxt] != INF)
					q.erase({d[nxt], nxt});
				d[nxt] = d[u] + cus;
				q.insert({d[nxt], nxt});
			}
		}
	}
	go(1);
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for(int x: ans){
		printf("%d ", x+1);
	}
	puts("");
}

