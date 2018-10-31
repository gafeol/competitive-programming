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

int n, m, k, s;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int go(int l){
	if(l == 1) return 0;
	//printf("go %d return %d %d %d\n", l, s, (l/2)*m, go((l+1)/2));
	return s + (l/2)*m + go((l+1)/2);
}

int solve(int i){
	if(i == 1 || i == 2) return i*s + m;
	return (i/2)*m + s + solve(i/2);
}

int main (){
	scanf("%d%d%d", &n, &m, &s);
	if(n == 3){
		printf("%d\n", m+solve(n-1));
		return 0;
	}
	printf("%d", m+go(n-1));
}

