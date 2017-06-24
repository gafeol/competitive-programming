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
int s[MAXN];

int nxt[MAXN];

map<int, vector<pii> > ind;

void sweep(){
	vector<pii> ev;
	for(auto& r : ind){
		ev = r.snd;
		for(pii e : ev){
			int t = e.snd;
			int u = e.fst;
		}
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		if(x > xx){
			swap(x, xx);
			swap(y, yy);
		}
		int end = (y < yy);
		ind[x].pb(pii(y, end));
		ind[xx].pb(pii(yy, 1-end));
	}
	sweep();		
}
