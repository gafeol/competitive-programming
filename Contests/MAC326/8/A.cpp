#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)

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

int n, m;
ll k;
int s[MAXN];
int deg;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


map<string, int> ind;

vector<pii> p[MAXN];

bool go(int q){
	const int inf = 0x3f3f3f3f;
	int pg = 0;
	for(int a=0;a<deg;a++){
		int bst = inf;
		for(pii prod: p[a]){
			if(prod.snd >= q)
				bst = min(bst, prod.fst);
		}
		if(bst == inf) return false;
		pg += bst;
	}
	return (pg <= k);
}

main (){
	for_tests(t, tt){
		scanf("%lld%lld", &n, &k);

		deg = 0;
		ind.clear();
		for(int a=0;a<n;a++){
			p[a].clear();
			pii prod;
			char tp[MAXN];
			char nome[MAXN];
			scanf(" %s %s %lld %lld", tp, nome, &prod.fst, &prod.snd);
			if(ind.find(tp) == ind.end())
				ind[tp] = deg++;
			p[ind[tp]].pb(prod);
		}
		int i = 0, j = 1000000000;
		while(i < j){
			int m = (i+j+1)/2;
			if(go(m))
				i = m;
			else
				j = m-1;
		}
		printf("%lld\n", i);
	}
}

