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

int n, m, k;
pii s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> x;

struct arv{
	int mn;
	int lz;
} tree[MAXN*24];


inline void unlaze(int idx, int i, int j){
	int aux = tree[idx].lz;
	if(aux == 0) return ;
	int m = (i + j)/2;
	tree[idx].lz = 0;
	if(i != j){
		tree[idx*2].mn += aux;
		tree[idx*2].lz += aux;
		tree[idx*2+1].mn += aux;
		tree[idx*2+1].lz += aux;
	}
}

void upd(int idx, int i, int j, int l, int r, int val){
	if(i > r || j < l) return ;
	unlaze(idx, i, j);
	if(i >= l && j <= r){
		tree[idx].mn += val;
		tree[idx].lz += val;
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i, m, l, r, val);
	upd(idx*2+1, m+1, j, l, r, val);
	tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return INT_MAX;
	unlaze(idx, i, j);
	if(i >= l && j <= r)
		return tree[idx].mn;
	int m = (i + j)/2;
	int ans = min(qry(idx*2, i, m, l, r), qry(idx*2+1, m+1, j, l, r));
	tree[idx].mn = min(tree[idx*2].mn, tree[idx*2+1].mn);
	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		x.pb(i);
		x.pb(i+1);
		x.pb(j-1);
		x.pb(j);
		x.pb(i-1);
		x.pb(j+1);
		s[a] = pii(i, j);
	}
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	int tam = x.size();
	for(int a=0;a<n;a++){
		s[a].fst = lower_bound(x.begin(), x.end(), s[a].fst) - x.begin();
		s[a].snd = lower_bound(x.begin(), x.end(), s[a].snd) - x.begin();
		upd(1, 0, tam, s[a].fst, s[a].snd, 1);
	}
	for(int a=0;a<n;a++){
		if(qry(1, 0, tam, s[a].fst, s[a].snd) > 1){
			printf("%d\n", a+1);
			return 0;
		}
	}
	puts("-1");
}

