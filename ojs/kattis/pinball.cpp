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

int nxt[MAXN];

map<int, vector<pii> > ind;


struct seg{
	int x[2], y[2];
	int ind;

	seg(){}

	seg(int x1, int y1, int xx, int yy, int i){
		if(x1 > xx){
			swap(x1, xx);
			swap(y1, yy);
		}
		x[0] = x1;
		x[1] = xx;
		y[0] = y1;
		y[1] = yy;
		ind = i;
	}
} s[MAXN];

struct cmp{
	bool operator() (const int& ui, const int& oi) {
		if(ui == -1) return true;
		if(oi == -1) return false;
		seg u = s[ui];
		seg o = s[oi];
		double yy;
		for(int a=0;a<2;a++){
			if(u.x[a] >= o.x[0] && o.x[1] >= u.x[a]){
				yy = (double)((o.y[1] - o.y[0])/((double)(o.x[1] - o.x[0])))*(double)(u.x[a] - o.x[0]); 
				yy = o.y[0] + yy; 
				return ((double)u.y[a] < yy); 
			}
		}

		for(int a=0;a<2;a++){
			if(o.x[a] >= u.x[0] && u.x[1] >= o.x[a]){
				yy = (double)((u.y[1] - u.y[0])/((double)(u.x[1] - u.x[0])))*(double)(o.x[a] - u.x[0]); 
				yy = u.y[0] + yy;
				return (yy < (double)o.y[a]); 
			}
		}
		debug("	return false\n");
		return (u.ind < o.ind);
	}
};

multiset<int, cmp> q;

void sweep(){
	vector<pii> ev;
	for(auto& r : ind){
		ev = r.snd;
		if(r.fst > -10 && r.fst < 10){
//			printf("to em x = %d\n", r.fst);
//			printf("q.sz %d\n", (int)q.size());
		}
		for(pii e : ev){
			int t = e.snd;
			int i = e.fst;
			debug("	evs %d %d\n", i, t);
			if(t) continue;
		//	int sz = q.size();
			q.insert(i);
		//	if(sz - q.size() == 0)
//				printf("to em %d e dei insert em %d e o sz nao mudou %d\n", r.fst, i, sz);
		}
		for(pii e: ev){
			int t = e.snd;
			int i = e.fst;
			if(s[i].y[t] < s[i].y[1-t]){
				int lw = *(--q.find(i));
				nxt[i] = lw;
//				if(i < 10) printf("nxt[%d] = %d\n", i, lw);
			}
		}
		for(pii e: ev){
			int t = e.snd;
			int i = e.fst;
			if(!t) continue;
			q.erase(i);
		}
	}
}

double avalia(seg o, int x){
	if(x < o.x[0] || x > o.x[1]) return -1600000.;
	double yy = (double)((o.y[1] - o.y[0])/((double)(o.x[1] - o.x[0])))*(double)(x - o.x[0]); 
	yy += o.y[0];
	return yy;	
}

int end(int i){
	if(s[i].y[0] < s[i].y[1])
		return s[i].x[0];
	return s[i].x[1];
}

int main (){
	scanf("%d", &n);
	q.insert( -1);
	memset(nxt, -1, sizeof(nxt));
	for(int a=0;a<n;a++){
		int x, y, xx, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		if(x > xx){
			swap(x, xx);
			swap(y, yy);
		}
		s[a] = seg(x, y, xx, yy, a);
		ind[x].pb(pii(a, 0));
		ind[xx].pb(pii(a, 1));
	}
	int X;
	scanf("%d", &X);
	sweep();		
	int ini = -1;
	for(int a=0;a<n;a++){
		if(ini == -1){
			if(avalia(s[a], X) > -1500000)
				ini = a;
		}
		else if(avalia(s[ini], X) < avalia(s[a], X))
			ini = a;
	}
	int pos = X;
	while(ini != -1){
		pos = end(ini);
//		printf("to em %d vou pra %d prox %d\n", ini, pos, nxt[ini]);
		ini = nxt[ini];
		assert(ini != nxt[ini]);
	}
	printf("%d\n", pos);
}
