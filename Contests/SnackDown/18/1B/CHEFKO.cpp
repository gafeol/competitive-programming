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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


int main (){
	for_tests(t, tt){
		vector<tuple<int, int, int> > ev;
		multiset<int> q, qo;

		scanf("%d%d", &n, &k);
		for(int a=0;a<n;a++){
			int l, r;
			scanf("%d%d", &l, &r);
			ev.pb({l, 0, r});
			ev.pb({r, 1, l});
		}
		sort(ev.begin(), ev.end());
		int res = 0;
		for(auto it: ev){
			int l, t, r;
			tie(l, t, r) = it;
			if(t == 0){
				q.insert(l);
				if(q.size() > k){
					int val = *q.rbegin();
					qo.insert(val);
					q.erase(q.find(val));
				}
			}
			if(q.size() == k)
				res = max(res, l - (int)*q.rbegin());
			if(t == 1){
				if(!q.empty() && q.find(r) != q.end()){
					assert(q.find(r) != q.end());
					q.erase(q.find(r));
					if(q.size() < k && !qo.empty()){
						int bg = *qo.begin();
						qo.erase(qo.begin());
						q.insert(bg);
					}
				}
				else
					qo.erase(qo.find(r));
			}
		}
		printf("%d\n", res);
	}
}

