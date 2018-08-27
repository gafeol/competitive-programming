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

const int MAXN = 132745, inf = 1000000010;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct rec{
	int x, y, xx, yy;
	int ok;

	rec(){}
	rec(int ax, int ay, int axx, int ayy, int aok){
		x = ax;
		y = ay;
		xx = axx;
		yy = ayy;
		ok = aok;
	}
} tree[MAXN*4];

rec s[MAXN];

rec inter(rec a, rec b){
	if(!a.ok) return a;
	if(!b.ok) return b;

	rec c;
	c.x = max(a.x, b.x);
	c.y = max(a.y, b.y);
	c.xx = min(a.xx, b.xx);
	c.yy = min(a.yy, b.yy);

	c.ok = 1;
	if(c.xx < c.x || c.yy < c.y)
		c.ok = 0;
	
	return c;
}

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = s[i];
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	tree[idx] = inter(tree[idx*2], tree[idx*2+1]);
}

rec qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return rec(-inf, -inf, +inf, inf, 1);
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)/2;
	return inter(qry(idx*2, i, m, l, r),
					qry(idx*2+1, m+1, j, l, r));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, y, xx, yy;
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		s[a] = rec(x, y, xx, yy, 1);
	}
	build(1, 0, n-1);
	for(int a=1;a<n-1;a++){
		rec  A = qry(1, 0, n-1, 0, a-1);
		rec B = qry(1, 0, n-1, a+1, n-1);
		rec ans = inter(A, B);
		if(ans.ok){
			printf("%d %d\n", ans.x, ans.y);
			return 0;
		}
	}
	rec ans = qry(1, 0, n-1, 0, n-2);
	if(ans.ok){
		printf("%d %d\n", ans.x, ans.y);
		return 0;
	}
	ans = qry(1, 0, n-1, 1, n-1);
	if(ans.ok){
		printf("%d %d\n", ans.x, ans.y);
		return 0;
	}
}

