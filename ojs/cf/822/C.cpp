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
ll best[MAXN];

struct trip{
	int l, r;
	ll c;
} s[MAXN];

ll res;

map<int, vector<pii> > ev;


void open(int i){
	ll tam = s[i].r - s[i].l + 1;

	if(tam > k) return ;
	if(best[k - tam] != -1)
		res = min(res, best[k-tam] + s[i].c); 
}

void close(int i){
	ll tam = s[i].r - s[i].l + 1;
	if(best[tam] == -1)
		best[tam] = s[i].c;
	best[tam] = min(best[tam], s[i].c);
}

void sweep(){
	vector<pii> e;
	for(auto& it: ev){
		e = it.snd;
		int t = it.fst;
		for(pii x: e){
			if(x.snd == 0)
				open(x.fst);
		}

		for(pii x: e){
			if(x.snd == 1)
				close(x.fst);
		}
	}
}

int main (){
	memset(best, -1, sizeof(best));
	res = LLONG_MAX;
	scanf("%d %d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d %d %lld", &s[a].l, &s[a].r, &s[a].c);
		ev[s[a].l].pb(pii(a, 0));
		ev[s[a].r].pb(pii(a, 1));
	}
	sweep();
	if(res != LLONG_MAX)
		printf("%lld\n", res);
	else
		puts("-1");
}
