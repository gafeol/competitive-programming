#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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
	//	write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
const ll modn2 = 10000019;
inline ll mod(ll x) { return x % modn; }

const int MAXK = 1003, MAXQ = 2 * 30004 + 10010;
const int MAXN = MAXQ;

const ll INF = 9000000000000LL;

int n, m, k;

vector<pli> s;
ll dp[15009][MAXK];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct qry{
	int t, id;
};

vector<qry> q;

int L[MAXN], R[MAXN];
int acu[MAXN];
ll pot[MAXK];

int h;

inline ll f(int h){
	ll res = 0;
	ll mx = 0;
	for(int a=1;a<=k;a++){
		mx = mod(max(mx, dp[h][a]));
		res = mod(res + mod(mx*pot[a-1]));
	}
	return res;
}

inline bool sup(int i, int j, int l, int r){
	return (i < l && j > r);
}

inline void add(int id){
	h++;
	int pes = s[id].snd;
	ll val = s[id].fst;
	for(int a=0;a<=k;a++){
		dp[h][a] = dp[h-1][a];
		if(a >= pes)
			dp[h][a] = max(dp[h][a], dp[h-1][a-pes] + val);
	}
}

void go(int i, int j){
	if(i == j){
		if(q[i].t == 3)
			printf("%lld\n", f(h));
		return ;
	}
	int m = (i+j)/2;	

	if(acu[m] - (i == 0 ? 0 : acu[i-1]) != 0){
		int old = h;
		for(int a=m+1;a<=j;a++){
			if(q[a].t == 1 || q[a].t == 3) continue;
			int id = q[a].id;
			if(sup(L[id], R[id], i, m))
				add(id);	
		}	
		go(i, m);

		h = old;
	}


	if(acu[j] - acu[m] != 0){
		int old = h;
		for(int a=i;a<=m;a++){
			if(q[a].t == 2 || q[a].t == 3) continue;
			int id = q[a].id;
			if(sup(L[id], R[id], m+1, j))
				add(id);
		}
		go(m+1, j);
		h = old;
	}
}

int main (){
	scanf("%d%d", &n, &k);

	pot[0] = 1;
	for(int a=1;a<k;a++)
		pot[a] = mod(pot[a-1]*modn2);

	const int inf = 1e7;
	for(int a=0;a<n;a++){
		pli x;
		scanf("%lld %d", &x.fst, &x.snd);
		s.pb(x);
		q.pb({1, a});
		L[a] = a;
		R[a] = inf;
	}

	scanf("%d", &m);
	for(int a=0;a<m;a++){
		qry p;
		scanf("%d", &p.t);
		if(q.size() > 0) acu[q.size()] = acu[q.size()-1];
		if(p.t == 1){
			pli x;
			scanf("%lld %d", &x.fst, &x.snd);
			s.pb(x);
			p.id = (int)s.size()-1;
			L[p.id] = q.size();
			R[p.id] = inf;
		}
		else if(p.t == 2){
			scanf("%d", &p.id);
			p.id--;
			R[p.id] = q.size();
		}
		else
			acu[q.size()]++;
		q.pb(p);
	}
	n = s.size();
	m = q.size();

	for(int a=0;a<=k;a++)
		dp[0][a] = -INF;
	dp[0][0] = 0;
	go(0, m-1);
}
