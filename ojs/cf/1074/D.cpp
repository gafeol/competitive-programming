#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
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

const int MAXN = 412345;

int n;

int p[MAXN];
int x[MAXN];
int sz[MAXN];

map<int, int> mrk;

int raiz(int u){
	if(p[u] == u) return u;
	
	raiz(p[u]);	
	x[u] ^= x[p[u]];
	return p[u] = raiz(p[u]);
}

int qry(int i, int j){
	if(raiz(i) != raiz(j)) return -1;
	return (x[i]^x[j]);
}

void join(int i, int j, int x){
	if(raiz(i) == raiz(j)) return ;
	int ir = raiz(i);
	int jr = raiz(j);
	if(sz[ir] < sz[jr]){
		swap(ir, jr);
		swap(i, j);
	}
	p[jr] = ir;
	sz[ir] += sz[jr];
	::x[jr] = (x^::x[j]^::x[i]);
}

int main(){
	scanf("%d", &n);
	int last = 0;
	for(int a=0;a<n;a++){
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j);
		i ^= last;
		j ^= last;
		if(i > j) swap(i, j);
		j++;
		if(mrk.find(i) == mrk.end()){
			int sz = mrk.size();	
			p[sz] = sz;
			::sz[sz] = 1;
			mrk[i] = sz;
		}
		if(mrk.find(j) == mrk.end()){
			int sz = mrk.size();	
			p[sz] = sz;
			::sz[sz] = 1;
			mrk[j] = sz;
		}
		i = mrk[i];
		j = mrk[j];
		if(t == 1){
			int x;
			scanf("%d", &x);				
			if(qry(i, j) != -1) continue;
			x ^= last;
			join(i, j, x);
		}
		else{
			int ans = qry(i, j);
			last = abs(ans);
			printf("%d\n", ans);
		}
		//for(auto it: mrk){
//			printf("%d -> %d / p %d x %d\n", it.fst, it.snd, p[it.snd], x[it.snd]);
		//}
	}
}
