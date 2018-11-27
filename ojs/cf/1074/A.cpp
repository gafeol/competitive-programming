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

vector<int> s;

int acu[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int j;
		scanf("%d", &j);
		s.pb(j);
	}
	s.pb(1000000000);
	sort(s.begin(), s.end());

	for(int a=0;a<m;a++){
		int j1, j2, i;
		scanf("%d%d%d", &j1, &j2, &i);
		if(j1 > 1)
			continue;	
		int pos = upper_bound(s.begin(), s.end(), j2) - s.begin();
		acu[0]++;
		acu[pos]--;
	}
	int res = INT_MAX;
	for(int a=0;a<s.size();a++){
		if(a > 0)
			acu[a] += acu[a-1];
		res = min(res, a + acu[a]);
	}
	printf("%d\n", res);
}
