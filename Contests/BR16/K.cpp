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
int s[MAXN][3];

int p[MAXN];

namespace f{
	const int maxv = 110;
	const int maxe = 500;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;
	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];

	bool bfs(int s, int t){
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b){
			for(int i = es[qu[a]];i != -1;i = nx[i]){
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
		for(int &i = cr[u];i != -1;i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}

	num max_flow(int s, int t){
		num fl= 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;

	}

	void reset_all(int n2 = maxv){ n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow(){ memset(fl, 0, sizeof(num) * en); }
	void add_edge(int a, int b, num c, num rc=0){
		fl[en] = 0; to[en] = b; cp[en] = c; nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;

	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a][0], &s[a][1]);
		s[a][0]--;
		s[a][1]--;
	}
	int ans = 0;
	int S = n*2 + 1, T = n*2 + 2;
	for(int w=0;w<n;w++){
		int cnt = 0;
		for(int a=0;a<n;a++){
			if(s[a][0] == w || s[a][1] == w){
				cnt++;
			}
		}
		if(cnt == 0){
			ans++;
			continue;
		}
		if(cnt > n/2)
			continue;
		f::reset_all(n*2 + 3);
		f::reset_flow();
		int F = 0;
		for(int a=0;a<n;a++){
			int mn = 0;
			if(s[w][0] == a || s[w][1] == a)
				mn = 1;
			f::add_edge(a+n, T, max(cnt-1-mn, 0));
			if(a == w) continue;
			if(s[a][0] != w && s[a][1] != w){
				f::add_edge(S, a, 1);	
				F++;
				f::add_edge(a, s[a][0]+n, 1);
				f::add_edge(a, s[a][1]+n, 1);
			}
		}
		if(F > f::max_flow(S, T))
			ans++;
	}
	printf("%d\n", ans);
}

