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

int bit[MAXN];

struct pti{
	int x, y, c;
} s[MAXN];


bool cmp(pti a, pti b){
	return a.y < b.y;
}

vector<int> X;

set<int> pos[MAXN];

map<int, vector<pii> > lin;

int res;

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i, int val){
	i+=2;
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

void sweep(){
	vector<pii> v;
	for(auto& it : lin){
		v = it.snd;
		for(pii ev: v){
			int x = ev.fst;
			int cor = ev.snd;
			int l = *(--pos[cor].upper_bound(x));
			int r = *pos[cor].upper_bound(x); 
			res = max(res, qry(r-1) - qry(l));
		}

		for(pii ev: v){
			int x = ev.fst;
			int cor = ev.snd;
			upd(x, 1);
			pos[cor].insert(x);
		}
	}
	for(int a=1;a<=k;a++){
		int l = *pos[a].begin();
		pos[a].erase(pos[a].begin());
		while(!pos[a].empty()){
			int r = *pos[a].begin();
			res = max(res, qry(r-1) - qry(l));
			l = r;
			pos[a].erase(pos[a].begin());
		}
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &k);

		memset(bit, 0, sizeof(bit));	
		res = 0;
		X.clear();
		lin.clear();
		for(int a=1;a<=k;a++){
			pos[a].clear();
			pos[a].insert(0);
			pos[a].insert(n + 1);
		}

		for(int a=0;a<n;a++){
			int x, y, c;
			scanf("%d%d%d", &s[a].x, &s[a].y, &s[a].c);
			X.pb(s[a].x);
		}
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		for(int a=0;a<n;a++){
			s[a].x = lower_bound(X.begin(), X.end(), s[a].x) - X.begin() + 1;
			lin[s[a].y].pb(pii(s[a].x, s[a].c));
		}

		sweep();

		printf("%d\n", res);
	}
}
