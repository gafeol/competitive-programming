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

int n, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

struct nmb {
	string s;
	bool operator< (const nmb &a) const {
		if (s.size() < a.s.size()) return true;
		if (s.size() > a.s.size()) return false;
		return s < a.s;
	}
	nbm operator- (const nmb &a) const {
		nbm ns;
		ns.s = s;
		int last = ns.s.size();
		for (int i=a.s.size()-1;i>=0;i--) {

		}
	}
}

string s;
map<string, string> m;
vector<nmb> g;

int main (){
	scanf("%d", &n);
	cin >> s;
	for(int a=0;a<n;a++){
		string a, b;
		cin >> a >> b;
		m[b] = a;
		g.pb({b});
	}
	sort(g.begin(), g.end());
	for (int i=g.size()-1;i>=0;i--) {
		
	}
}

