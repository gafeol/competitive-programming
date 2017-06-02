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
pll s[MAXN];
ll d;
int deg = 0;

pii p[2];

map<int, vector<ppi> > ev;

ppi mk(int a, int b, int c){
	return ppi(pii(a, b), c);
}

pii trans(int x, int y){
	return pii(x + y, x - y);
}

void fail(){
	puts("impossible");
	exit(0);
}

void add(int x, int y){
	pii i = trans(x, y-d);
	pii ii = trans(x-d, y);
	ev[i.fst].pb(mk(i.snd, ii.snd, 1));	
	pii j = trans(x+d, y);
	pii jj = trans(x, y+d
	ev[j.fst+1].pb(mk(j.snd, jj.snd, -1));
}

void go(){
	int i = INT_MIN, j = INT_MAX;
	int cnt = 0, ult = 0;
	vector<pii> v;
	for(auto& it: ev){
		ult = cnt;
		int x = it.fst;
		v = it.snd;
		for(ppi e: v){
			cnt += e.snd;
			i = max(i, e.fst.fst);
			j = min(j, e.fst.snd);
		}
		if(cnt == n){
			p[0] = pii(x, i);
			deg++;
		}
		else if(ult == n){
			p[1] = pii(x-1, j);
			deg++;
		}
	}
}

vector<int> X, Y;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
		X.pb(trans(x, y).fst);
		Y.pb(trans(x, y).snd);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	scanf("%d", &d);
	for(int a=0;a<n;a++)
		add(s[a].fst, s[a].snd);

	go();
	if(deg < 2 || p[0].snd > p[1].snd){
		puts("impossible");
		return 0;
	}
	int mx = X[(n+1)/2];
	int my = Y[(n+1)/2];
	int rx, ry;
	if(mx >= p[0].fst && mx <= p[1].fst)
		rx = mx;
	else
		rx = (abs(p[0].fst - mx) < abs(p[1].fst - mx) ? p[0].fst : p[1].fst);

	if(my >= p[0].snd && my <= p[1].snd)
		ry = my;
	else
		ry = (abs(p[0].snd - my) < abs(p[1].snd - my) ? p[0].snd : p[1].snd);
		
}
