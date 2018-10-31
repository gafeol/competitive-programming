#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int inf = 1000000;


namespace f {
	const int maxv = 10009 + 8;
	const int maxe = (maxv*5 + maxv) * 2;
	typedef int num;
	num inf = INT_MAX;
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
int n, m, k;
int s[MAXN];

pii qry[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

void fail(){
	puts("unfair");
	exit(0);
}

int main (){
	scanf("%d%d%d", &n, &k, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d", &qry[a].fst, &qry[a].snd);
	}
	int ult = 0, ultq = 0;
	sort(qry, qry+m);
	int soma = 0;


	int S = m + 6, T = S + 1;
	f::reset_all();
	qry[m] = pii(k, n);
	for(int a=0;a<=m;a++){
		//printf("ult %d\n", ult);
		int x;
		x = qry[a].fst;
		int cnt[5];
		for(int a=0;a<5;a++)
			cnt[a] = 0;

		int pos =0;
		while(ult < x){
			ult++;
			cnt[(ult%5)]++;
			pos++;
			//printf("soma ult %d  %d\n", ult, (ult%5));
		}
		int qtd = qry[a].snd;
		int aux = qtd;	
		qtd -= ultq;
		ultq = aux;
		if(qtd < 0 || qtd > pos)
			fail();			
		soma += qtd;			
		f::add_edge(S, a, qtd);
		//printf("S -> %d cp %d\n", a, qtd);
		for(int i=0;i<5;i++){
			//printf("%d -> %d (%d)\n", a, m+1+i, cnt[i]);
			f::add_edge(a, m+1+i, cnt[i]);
		}
	}
	for(int a=0;a<5;a++){
		f::add_edge(m+1+a, T, n/5);
		//printf("%d->T %d\n", m+1+a, n/5);
	}
	if(soma == n && f::max_flow(S, T) == n)
		puts("fair");
	else fail();
}

