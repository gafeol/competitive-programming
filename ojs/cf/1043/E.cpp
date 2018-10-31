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

const int MAXN = 312345;

int n, m, k;
int s[MAXN];

struct p{
	ll x, y;
	int id;

	bool operator < (const p o) const {
		return x - y < o.x - o.y;
	}
} sum[MAXN];

vector<p> q;
p ori[MAXN];

bool ok(int i, int o){
	return (ori[i].x + ori[o].y <= ori[i].y + ori[o].x);
}

ll res[MAXN];


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ori[a] = {x, y, a};
		q.pb({x, y, a});
	}
	sort(q.begin(), q.end());
	ll sumx = 0; ll sumy = 0;
	for(int a=0;a<n;a++){
		sumy += q[a].y;
	}
	for(int a=0;a<n;a++){
		sumy -= q[a].y;
		res[q[a].id] = sumx + sumy + q[a].x*(n-a-1ll) + q[a].y*a;
		sumx += q[a].x;
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		i--;j--;
		if(ok(i, j)){
			res[i] -= ori[i].x + ori[j].y;
			res[j] -= ori[i].x + ori[j].y;
		}
		else{
			res[i] -= ori[i].y + ori[j].x;
			res[j] -= ori[i].y + ori[j].x;
		}
	}
	for(int a=0;a<n;a++)
		printf("%lld%c", res[a], " \n"[a==n-1]);
}

