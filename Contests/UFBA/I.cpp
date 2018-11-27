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
ll s[MAXN];

ll tree[MAXN*4];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx] = abs(s[i+1] - s[i]);
		return ;
	}
	int m = (i + j)/2;
	build(idx*2, i,m);
	build(idx*2+1, m+1, j);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

void upd(int idx, int i, int j, int l){
	if(l < i || l > j) return ;	
	if(i == j){
		tree[idx] = abs(s[i+1] - s[i]);
		return ;
	}
	int m = (i + j)/2;
	upd(idx*2, i,m, l);
	upd(idx*2+1, m+1, j, l);
	tree[idx] = max(tree[idx*2], tree[idx*2+1]);
}

ll qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	if(i >= l && j <= r) return tree[idx];
	int m = (i + j)/2;
	return max(qry(idx*2, i, m, l, r),
				qry(idx*2+1, m+1, j,l, r));
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a);
	}
	s[n] = 3000000000LL;
	build(1, 0, n-1);
	for(int a=0;a<m;a++){
		int t, pos;
		ll h;
		scanf("%d%d%lld", &t, &pos, &h);
		pos--;
		if(t == 1){
			s[pos] = h;
			upd(1, 0, n-1, pos);	
			if(pos > 0)
				upd(1, 0, n-1, pos-1);
		}
		else{
			int i = 0, j = pos-1;
			int res = 0;
			if(pos > 0){
				while(i < j){
					int m = (i + j)/2;
					if(qry(1, 0, n-1, m, pos-1) <= h)
						j = m;
					else
						i = m+1;
				}
				if(abs(s[i] - s[i+1]) > h)
					i++;
				res += pos - i;
				//printf("go left %d\n", res);
			}

			if(pos < n-1){
				i = pos, j = n-1;
				while(i < j){
					int m = (i+j+1)/2;
					//printf("i %d j %d m %d\n", i, j, m);
					//printf("test %d %d %d %d %d : %lld <= %lld\n", 1, 0, n-1, pos, m, qry(1, 0, n-1, pos, m), h);
					if(qry(1, 0, n-1, pos, m) <= h)
						i = m;
					else
						j = m-1;
				}
				//printf("pos %d i %d\n", pos, i);
				//printf("go right %d\n", i - pos + 1);
				if(abs(s[i] - s[i+1]) > h)
					i--;
				res += i - pos + 1;	
				//printf("go right %d\n", i - pos + 1);
				//printf("i %d\n", i);
			}

			printf("%d\n", res+1);
		}
	}
}

