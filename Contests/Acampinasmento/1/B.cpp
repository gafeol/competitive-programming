
#include<bits/stdc++.h>

using namespace std;

int nar;

namespace f{
	const int maxv = 510;
	const int maxe = 260*260*2;
	typedef int num;
	num inf  = INT_MAX;
	int n  = maxv;
	int to[maxe], en, nx[maxe], es[maxe], lv[maxe], qu[maxe], cr[maxe];
	num cp[maxe], fl[maxe];

	bool bfs(int s, int t){
		memset(lv, -1, sizeof(int)*n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s;
		cr[s] = es[s];
		while(a < b){
			for(int i= es[qu[a]];i != -1;i = nx[i]){
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
		if(u == t){
			return mx;
		}
		for(int &i = cr[u];i != -1;i = nx[i]){
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1){
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))){
					fl[i] += a;
					fl[i^1] -= a;
					return a;
				}
			}
		}
		return 0;
	}

	num max_flow(int s, int t){
		num fl = 0;
		int a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int)*n); }
	void reset_flow() { memset(fl, 0, sizeof(int)*en);}

	void add_edge(int a, int b, num c, num rc=0){
		fl[en] = 0; to[en] = b; cp[en] = c; nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
		nar += 2;
	
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	f::reset_all();
	int s = 0, t = n+m+2;
	for(int a=1;a<=n;a++){
		f::add_edge(s, a, 1);
		int u;
		scanf("%d", &u);
		while(u != 0){
			f::add_edge(a, u+n, 1);
			scanf("%d", &u);
		}
	}
	for(int a=1;a<=m;a++){
		f::add_edge(a+n, t, 1);
	}
	printf("%d\n", f::max_flow(s, t));
	for(int a=1;a<=n;a++){
		for(int i=f::es[a];i != -1;i = f::nx[i]){
			if(f::fl[i] > 0){
				printf("%d %d\n", a, f::to[i]-n);
			}
		}
	}
}

