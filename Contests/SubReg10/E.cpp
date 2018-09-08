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

int sq(int x){
	return x*x;
}

int dist(int i, int j, int ii, int jj){

	return sq(ii - i)+sq(jj - j);		
}

int main (){
	int l, c, r1, r2;
	while(scanf("%d%d%d%d", &l, &c, &r1, &r2) && l+c+r1+r2){
		if(2*r1 <= min(l, c) && 2*r2 <= min(l, c) && dist(r1, r1, l-r2, c-r2) >= sq(r1+r2))
			puts("S");
		else
			puts("N");
	}
}

