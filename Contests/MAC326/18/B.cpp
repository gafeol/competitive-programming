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

set<pii> q;

set<pii> dj;
unordered_map<int, int> d;

int main (){
	for_tests(t, tt){
		scanf("%d%d", &k, &n);
		for(int a=0;a<n;a++){
			scanf("%d%d", &r, &m); 
			for(int i=0;i<=1000;i++){
				if(r + m*i >= k) break;
				q.insert({r+m*i, m});
			}
		}
		q.insert({k, 0});
		dj.insert({0, 0});
		d[0] = 0;
		int res = 0;
		while(!dj.empty()){
			int fl = dj->snd;
			dj.erase(dj.begin());
				
		}
	}
}

