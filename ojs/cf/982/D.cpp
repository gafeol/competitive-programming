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
int s[MAXN], mrk[MAXN], p[MAXN], sz[MAXN];

multiset<int> tams;

set<int> sq;

map<int, vector<int> > mp;

int nc;

int raiz(int i){
	if(p[i] == i) return i;
	return p[i] = raiz(p[i]);
}

void join(int i, int j){
	debug("join %d %d\n", i, j);
	i = raiz(i);
	j = raiz(j);
	if(i == j) return ;
	debug("!= %d %d\n", i, j);
	nc--;
	tams.erase(tams.find(sz[i]));
	debug("========erase %d\n", sz[i]);
	tams.erase(tams.find(sz[j]));
	debug("========erase %d\n", sz[j]);
	if(sz[i] < sz[j])
		swap(i, j);
	sz[i] += sz[j];
	tams.insert(sz[i]);
	debug("=======insert %d\n", sz[i]);
	p[j] = i;
}

void add(int i){
	if(i-1 >= 0 && mrk[i-1])
		join(i-1, i);
	if(i+1 < n && mrk[i+1])
		join(i, i+1);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		p[a] = a;
		sz[a] = 1;
		sq.insert(s[a]);
		mp[s[a]].push_back(a);
	}
	nc = 0;
	int ansv = *sq.begin(), ansc = 0;
	while(!sq.empty()){
		int val = *sq.begin();
		sq.erase(sq.begin());
		for(int i: mp[val]){
			debug("val %d i %d\n", val, i);
			nc++;
			debug("nc ++\n");
			tams.insert(1);
			debug("==========insert 1\n");
			mrk[i] = 1;
			add(i);
		}
		debug("val %d nc %d\n", val, nc);
		if(!tams.empty() && *tams.begin() == *tams.rbegin()){
			debug("nc %d tams %d\n", nc, (int)tams.size());
			assert(nc == tams.size());
			if(ansc < nc){
				ansc = nc;
				ansv = val+1;
				debug("ansc %d ans v %d\n", ansc, ansv);
			}
		}
	}
	printf("%d\n", ansv);
}

