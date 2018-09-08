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
const int MAXK = 16123;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

unordered_set<int> dp;

inline void add(int x){
	vector<int> ins;
	ins.clear();
	for(auto it: dp){
		ins.pb(it-x);
		ins.pb(it+x);
	}
	dp.clear();
	for(int val: ins)
		dp.insert(val);
}

int main (){
	while(scanf("%d%d", &n, &k) && n+k){
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		int imp = 0;
		vector<char> ans;
		for(int i=0;i<n;i++){
			dp.clear();
			dp.insert(0);
			for(int a=0;a<n;a++){
				if(a == i) continue;
				add(s[a]);
			}
			bool lo = (dp.find(k-s[i]) != dp.end());
			bool hi = (dp.find(k+s[i]) != dp.end());
			if(!lo && !hi){
				imp = 1;
				break;
			}
			else if(lo && hi)
				ans.pb('?');
			else if(lo)
				ans.pb('+');
			else
				ans.pb('-');

		}
		if(imp){
			puts("*");
			continue;
		}
		for(char c: ans)
			printf("%c", c);
		puts("");
	}
}

