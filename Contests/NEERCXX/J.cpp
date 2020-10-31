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

const int MAXN = 5123;

int n, m, k;
pii s[MAXN];
namespace f{
	const int maxv = 11234;
	const int maxe = 4*5123*2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];

	bool bfs(int s, int t){
		memset(lv, -1, sizeof(int)*n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b){
			for(int i=es[qu[a]];i != -1;i=nx[i]){
				if(cp[i] > fl[i] && lv[to[i]] == -1){
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

	num dfs(int u, int t, num mx){
		if(u == t) return mx;
		for(int &i = cr[u];i != -1;i=nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a=dfs(to[i], t, min(mx, cp[i] - fl[i]))){
					fl[i] += a;
					fl[i^1] -= a;
					return a;
				}
		return 0;
	}

	num max_flow(int s, int t){
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2 = maxv){ n = n2; en = 0; memset(es, -1, sizeof(int)*n);}
	void reset_flow(){ memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0){
		if(a >= 0 && a<m)
			debug("es[a] = en %d a %d to b %d c %d\n", en, a, b, c);
		fl[en] = 0; to[en] = b; cp[en] = c; nx[en] = es[a]; es[a] = en++;
		if(b >= 0 && b< m)
			debug("es[b] = en %d to a %d b %d c %d\n", en, a, b, c);
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
		
	}
}



int main (){
	scanf("%d%d", &n, &m);
	int S = m + n, T = m+n+1;
	for(int a=0;a<m;a++){
		scanf("%d %d", &s[a].fst, &s[a].snd);
		s[a].fst--;
		s[a].snd--;

	}
	int i=0, j = m+1;
	while(i < j){
		int mid = (i + j)/2;
		f::reset_all();
		f::reset_flow();
		debug("mid %d\n", mid);
		for(int a=0;a<m;a++){
			f::add_edge(S, a, 1);
			f::add_edge(a, m+s[a].fst, 1);
			f::add_edge(a, m+s[a].snd, 1);
		}
		for(int a=0;a<n;a++)
			f::add_edge(m+a, T, mid);
		
		if(f::max_flow(S, T) == m)
			j = mid;
		else
			i = mid+1;
	}
	printf("%d\n", i);
	f::reset_all();
	f::reset_flow();
	for(int a=0;a<m;a++){
		f::add_edge(S, a, 1);
		f::add_edge(a, m+s[a].fst, 1);
		f::add_edge(a, m+s[a].snd, 1);
	}
	for(int a=0;a<n;a++)
		f::add_edge(m+a, T, i);

	f::max_flow(S, T);

	for(int a=0;a<m;a++){
		int i = f::es[a];
		while(i != -1){
			debug("i %d fl %d cp %d to %d\n", i, f::fl[i], f::cp[i], f::to[i]);
			if(f::fl[i] == 1){
				if(f::to[i] == m+s[a].fst)
					printf("%d %d\n", 1+s[a].fst, 1+s[a].snd);
				else
					printf("%d %d\n", 1+s[a].snd, 1+s[a].fst);
			}
			i = f::nx[i];
		}
	}
}
