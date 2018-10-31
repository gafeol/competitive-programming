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
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


int main (){
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int a=0;a<n+m;a++){
		vector<pii> ans;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(i + j == a+1){
					ans.pb(pii(i, j));
				}
			}
		}
		for(int i=0;i<ans.size();i++){
			pii p = ans[i];
			if(i > 0)
				printf("&");
			bool has = (p.fst == 0 || p.snd == 0);
			
			if(!has)
				printf("(");

			if(p.fst != 0)
				printf("x%d", p.fst);
			if(!has)
				printf("|");
			if(p.snd != 0)
				printf("y%d", p.snd);

			if(!has)
				printf(")");
		}
		puts("");
	}
}

