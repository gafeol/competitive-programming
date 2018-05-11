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

multiset<pii> q;

int r(int a){
	int b = n;
	int ans = a/b;
	int sob = a%b;
	if(sob*2 >= b)
		ans++;
	return ans;
}

int nxt[MAXN], cus[MAXN];
int d[MAXN];

int mn;

int raiz(int u, int c){
	if(c > mn) return 0;
	if(d[u] != -1) return d[u];
	return d[u] = 1+raiz(nxt[u], cus[u]);
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		int cnt = n;
		int res = 0; 
		mn = INT_MAX;
		for(int a=0;a<n;a++){
			int rt = (100*a)%n;
			d[rt] = -1;
			int nxt[rt] = (100*(a+1))%n;
			cus[rt] = r((a+1)*100);
			mn = min(mn, cus[rt]);
		}
		for(int a=0;a<n;a++){
			int rt = (100*a)%n;
			raiz(rt, 0);
		}

		q.clear();
		for(int a=0;a<m;a++){
			scanf("%d", s+a);
			cnt-=s[a];
			res += r(s[a]*100);
			int rt = (s[a]*100)%n;
			q.insert(pii(d[rt], rt));
		}
		while(cnt--){
			pii top = *q.begin();
			debug("pega %d\n", -top.fst);
			if(-top.fst < r(100)){
				debug("%d < %d\n", -top.fst, r(100));
				res += r(100);
				continue;
			}
			q.erase(q.begin());
			res += -top.fst;
			debug("res += %d\n", -top.fst);
			int i = top.snd;
			s[i]++;
			int w = r((s[i] + 1)*100) - r(s[i]*100);
			debug("de %d -> %d w %d\n", s[i], s[i]+1, w);
			q.insert(pii(-w, i));
		}
		printf("Case #%d: %d\n", tt, res);
	}
}

