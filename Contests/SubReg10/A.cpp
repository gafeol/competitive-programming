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

const int MAXN = 212;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char s[MAXN];

int main (){
	int d;
	while(scanf("%d %s", &d, s) && s[0] != '0'){
		n = strlen(s);	
		int lz = 1;
		for(int a=0;a<n;a++){
			if(s[a]-'0' == d) continue;
			if(s[a] == '0' && lz == 1) continue;
			printf("%c", s[a]);
			lz = 0;
		}
		if(lz)
			printf("0");
		puts("");
	}
}

