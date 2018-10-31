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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> has[MAXN];

int tot, nd;
int mrk[MAXN];

void add(int x){
	if(mrk[x] == 0)
		nd++;
	tot++;
	mrk[x]++;
}

void rmv(int x){
	if(mrk[x] == 1)
		nd--;
	tot--;
	mrk[x]--;
}

int main (){
	while(scanf("%d%d", &n, &k)!=EOF){
		memset(mrk, 0, sizeof(mrk));
		tot = 0;
		nd = 0;
		for(int a=0;a<n;a++){
			has[a].clear();
			has[a+n].clear();
		}

		for(int a=0;a<n;a++){
			int x;
			scanf("%d", &x);
			while(x--){
				int y;
				scanf("%d", &y);
				has[a].pb(y);
				has[a+n].pb(y);
			}
		}
		int res = INT_MAX;
		int j = 0;
		for(int i=0;i<n;i++){
			if(j < i) j = i;
			while(j < 2*n && nd < k){
				for(int x: has[j])
					add(x);
				j++;
			}
			if(nd == k)
				res = min(res, tot);
			for(int x: has[i])
				rmv(x);
		}
		if(res == INT_MAX)
			puts("-1");
		else 
			printf("%d\n", res);
	}
}

