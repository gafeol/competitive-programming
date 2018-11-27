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

int n, m;
ll k;
int s[MAXN];

struct arv{
	int tot;
	ll som;
} tree[MAXN*4];

arv join(arv a, arv b){
	return {a.tot + b.tot, a.som + b.som};
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = {0, 0ll};
		return ;
	}
	int m= (i + j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

void upd(int idx, int i, int j, int l, ll x){
	if(i > l || j < l) return ;
	
	if(i == j){
		tree[idx] = {1, x};
		return ;
	}
	int m= (i + j)/2;
	upd(idx*2, i, m, l, x);
	upd(idx*2+1, m+1, j, l, x);
	tree[idx] = join(tree[idx*2], tree[idx*2+1]);
}

arv qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return {0, 0};
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i + j)/2;
	return join(qry(idx*2, i, m, l, r),
				qry(idx*2+1, m+1, j, l, r));

}


vector<int> pos[MAXN];
bool has[MAXN];
int R = n-1;
ll som = 0;
int tot = 0;

ll valor(){
	if(R < 0) return 0;
	int sob = tot%m;
	if(sob == 0) sob = m;

	if(tot == sob)
		return som;

	int i = 0, j = R;
	arv qr;
	while(i < j){
		int m = (i + j)/2;
		qr = qry(1, 0, n-1, m, R);
		if(qr.tot < sob)
			j = m-1;
		else if(qr.tot > sob)
			i = m+1;
		else
			i = j = m;
	}
	qr = qry(1, 0, n-1, i, R);
	return 2ll*som - qr.som;
}
	
int main (){
	for_tests(t, tt){
		scanf("%d%d%lld", &n, &m, &k);
		build(1, 0, n-1);
		vector<int> x;
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
			x.pb(s[a]);
		}
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());

		for(int a=0;a<n;a++){
			has[a] = false;
			pos[s[a]].pb(a);
		}
			
		tot = som = 0;
		R = n-1;

		int res = 0, ires = 1;
		for(int d: x){
			if(d > k) break;
			for(int p: pos[d]){
				if(p > R) 
					continue;
				upd(1, 0, n-1, p, d);	
				som += d;
				tot++;
				has[p] = true;
			//	printf("Add ponto %d de valor %d\n", p, d);
			}
			//printf("valor() %lld\n", valor());
			while(valor() > k){
			//	puts("deu maior");
				if(has[R]){
					som -= s[R];
					tot--;
				}
				R--;
				//printf("R %d\n som %lld tot %d\n", R, som, tot);
			}
			if(tot > res){
				res = tot;
				ires = d;
			}
		}
		printf("%d %d\n", res, ires);

		for(int a=0;a<n;a++){
			pos[s[a]].clear();
			has[a] = false;
		}
	}
}

