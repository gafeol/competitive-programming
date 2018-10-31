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

const int MAXN = 112345;

int n, m;
tuple<int, int, int> s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

set<pii> q;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		q.clear();
		for(int a=0;a<n;a++){
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			s[a] = {i, j, k};
		}
		sort(s, s+n);
		int res = 0;
		for(int a=0;a<n;a++){
			int i, j, k;
			tie(i, j, k) = s[a];																
			auto it = q.lower_bound(pii(j, k));
			if(it != q.begin()){
				it--;
				if(it->snd < k)
					continue;
			}
			auto nxt = q.upper_bound(pii(j, k));
			vector<pii> er;
			while(nxt != q.end() && nxt->snd > k){
				er.pb(*nxt);
				nxt++;
			}
			while(!er.empty()){
				q.erase(er.back());
				er.pop_back();
			}
			q.insert(pii(j, k));
			res++;
		}
		printf("%d\n", res);
	}
}

