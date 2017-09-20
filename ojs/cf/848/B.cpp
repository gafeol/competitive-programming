#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define int ll

const int MAXN = 2123456;

int n, m, k;

int w, h;

struct pt{
	int x, y;
	pt(int xx, int yy){
		x = xx;
		y = yy;
	}
	pt(){}
};

struct ev{
	int g, p, t, i;
	pt res;
} s[MAXN];

map<int, vector<int> > ind;

bool cmp(ev a, ev b){
	int xa, xb;
	if(a.g == 1)
		xa = a.p;
	else
		xa = -a.t;
	if(b.g == 1)
		xb = b.p;
	else
		xb = -b.t;
	return (xa > xb);
}

vector<int> v;
stack<int> st;

void sweep(){
	for(auto &r: ind){
		int d = r.fst;
		debug("diag %lld\n", d);
		v.clear();
		v = r.snd;
		while(!st.empty())
			st.pop();
		for(int it = v.size()-1;it >= 0;it--){
			int a = v[it];
			if(s[a].g == 2)
				st.push(a);
		}
		for(int a: v){
//			debug("ponto i %lld g %lld p %lld t %lld\n", s[a].i, s[a].g, s[a].p, s[a].t); 
			if(s[a].g == 2){
		//		if(st.top() != a) debug("FODEU\n");
				if(!st.empty())
					st.pop();
			}
			if(s[a].res.y == h && s[a].res.x < w){ //ta indo na vertical
				if(!st.empty()){
					int b = st.top();
					swap(s[a].res, s[b].res);
				}
			}
		}
	}
}

pt ans[MAXN];

main (){
	scanf("%lld%lld%lld", &n, &w, &h);
	for(int a=0;a<n;a++){
		scanf("%lld %lld %lld", &s[a].g, &s[a].p, &s[a].t);
		s[a].i = a;
		if(s[a].g == 1)
			s[a].res = pt(s[a].p, h);
		else
			s[a].res = pt(w, s[a].p);
	}
	sort(s, s+n, cmp);
	ind.clear();
	for(int a=0;a<n;a++){
		ind[s[a].p - s[a].t].pb(a);
	}
	sweep();
	for(int a=0;a<n;a++){
		ans[s[a].i] = s[a].res;
	}
	for(int a=0;a<n;a++){
		printf("%lld %lld\n", ans[a].x, ans[a].y);
	}
}

