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

ll s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct f{
	ll x, y;
	bool operator < (const f &o) const {
		long double va = ((long double)x)/y - (x/((long double)y+1.));
		long double vb = ((long double)o.x)/o.y - (o.x/((long double)o.y + 1.));
		return (va < vb);
	}
};


long double res;

int main (){
	for_tests(t, tt){
		int n, m;
		priority_queue<f> q;
		scanf("%d%d", &n, &m);
		res = 0;
		for(int a=0;a<n;a++){
			scanf("%lld", s+a);
			q.push({s[a]*s[a], 1});
			res += s[a];
		}
		res /= (long double)m;
		res = -(res*res);
		long double ans = 0;
		int cnt = m - n;
		while(cnt--){
			f mx = q.top();	
			q.pop();
			mx.y++;
			q.push(mx);
		}
		while(!q.empty()){
			f val = q.top();
			q.pop();
			ans += val.x/((long double)val.y);
		}
		res += ans/((long double)m);
		printf("Case #%d: %.9Lf\n", tt, res);
	}
}

