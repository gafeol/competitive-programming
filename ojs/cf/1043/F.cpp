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

const int MAXN = 300009;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> p;
vector<int> s;

vector<int> dc[MAXN];

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int mrk[MAXN];

int main (){
	clock_t clk = clock();
	for(int i = 2;i<MAXN;i++){
		if(dc[i].size() > 0) continue;
		p.pb(i);
		for(ll a = 1;i*a < MAXN;a++){
			dc[i*a].pb(i);
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, ox, dx;
		scanf("%d", &x);
		if(x == 1){
			puts("1");
			return 0;
		}
		dx = ox = x;
		for(int pri: dc[x]){
			while(x%(pri*pri) == 0){
				x /= pri;
				dx/=pri;
			}
			while(dx%pri == 0)
				dx/=pri;
		}
		if(dx > 1)
			dc[ox].pb(dx);
		s.pb(x);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	n = s.size();
	vector<int> ns;
	for(int a=0;a<n;a++){
		if(mrk[s[a]]) continue;
		ns.pb(s[a]);
		for(int i=2;i*s[a] < MAXN;i++)
			mrk[i*s[a]] = 1;
	}
	s = ns;
	n = s.size();
	int gc = 0;
	for(int a=0;a<n;a++){
		gc = gcd(gc, s[a]);
	}
	if(gc != 1){
		puts("-1");
		return 0;
	}
	int res = n;
	while(((double)clock()-clk)/CLOCKS_PER_SEC < 2.5){
		random_shuffle(s.begin(), s.end());
		int gc = 0;
		for(int a=0;a<n;a++){
			gc = gcd(gc, s[a]);
			if(gc == 1)	{
				res = min(res, a+1);
				break;
			}
		}
	}
	printf("%d\n", res);
}

