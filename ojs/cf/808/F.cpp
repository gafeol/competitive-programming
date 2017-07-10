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

namespace f {
	const int maxv = ;
	const int maxe =  * 2;
	typedef int num;
	num inf = /*INT_MAX*/;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					cr[to[i]] = es[to[i]];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		for(int &i = cr[u]; i != -1; i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}

struct card{
	int p, c, l;
	card(){}
	card(int pp, int cc, int ll){
		p = pp;
		c = cc;
		l = ll;
	}
};

vector<card> s;

bool cmp(card a, card b){
	return a.l < b.l;
}

void add(int i, int j, int val){
	if(s[j].c%2 == 0)
		swap(i, j);
	f::add_edge(i, j, val);
}

int main (){
	for(int a=2;a<MAXN;a++){
		if(mrk[a*b]) continue;
		for(ll b = a; a*b < MAXN;b++){
			mrk[a*b] = 1;
		}
	}
	scanf("%d%d", &n, &k);
	int um = -1;
	for(int a=0;a<n;a++){
		card aux;
		scanf("%d %d %d", &aux.p, &aux.c, &aux.l); 
		if(aux.c == 1 && um != -1){
			if(s[um].c < aux.c || (s[um].c == aux.c && aux.l < s[um].l){
				s[um] = aux;
			}
			continue;
		}
		if(aux.c == 1)
			um = s.size();
		s.pb(aux);
	}
	n = s.size();
	int s = n, t = n+1;
	sort(s.begin(), s.end(), cmp);
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			if(!mrk[s[a].c + s[b].c]){
				add(a, b, 2000)
			}
		}
	}
	for(int a=0;a<n;a++){
		add(n, 
	}

}
