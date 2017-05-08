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

const int MAXN = 212;

int n, m, k;
pii s[MAXN];
ll resa, resp;

map<int, vector<int> > pts;
map<int, int> has;

void fail(){
	puts("Impossible");
	exit(0);	
}

int sx[MAXC], sy[MAXC];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
		sx[s[a].fst]++;
		sy[s[a].snd]++;
	}
	for(int a=0;a<n;a++){
		if(sx[s[a].fst]&1)
			fail();
		if(sy[s[a].snd]&1)
			fail();
	}
	sort(s, s+n);
	for(int a=0;a<n;a++){
		pts[s[a].fst].pb(s[a].snd);
	}

	vector<int> v;
	int xx = -1;
	ll nl, sl;
	nl = sl = 0;
	for(auto& it : pts){
		int x = it.fst;
		debug("\nanalisando x %d\n", x);
		debug("resp %lld\n", resp);
		debug("resa %lld\n", resa);
	
		if(xx != -1){
			debug("adiciona resp %lld * (%d - %d)\n", nl, x, xx);
			resp += nl * (x - xx);
			debug("adiciona resa %lld * (%d - %d)\n", sl, x, xx);
			resa += sl * (x - xx);
		}
			
		v = it.snd;	
		if(v.size()&1)
			fail();

		int yy = -1;
		for(int y: v){
			if(yy != -1){
				resp += y - yy;
				yy = -1;			
			}
			else
				yy = y;
			debug("pontos em %d\n", y);
			if(has.find(y) != has.end()){
				has.erase(y);
				debug("ja tinha entao apago\n");
			}
			else{
				has[y] = 1;
				debug("nao tinha entao adiciono\n");
			}
		}
		
		if(has.size()&1)
			fail();
		
		sl = 0;
		nl = 0;
		for(auto i = has.begin();i != has.end(); ++i){
			auto j = i;
			++j;
			int y = i->fst;
			int yy = j->fst;

			sl +=  yy-y;
			nl += 2;
			++i;
		}
		xx = x;
	}
	if(!has.empty())
		fail();

	printf("%lld %lld\n", resa, resp);
}
