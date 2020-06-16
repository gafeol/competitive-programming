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
	scanf("%d", &n);
	string s;
	scanf("\n");
	for(int a=0;a<n;a++){
		getline(cin, s);
		int tam = s.size();
		int nb = 0, ng = 0;
		for(int i=0;i<tam;i++){
			nb += (s[i] == 'b' || s[i] == 'B');
			ng += (s[i] == 'g' || s[i] == 'G');
		}
		cout << s;
		printf(" is ");

		if(nb > ng)
			puts("A BADDY");
		else if(nb == ng)
			puts("NEUTRAL");
		else
			puts("GOOD");
	}
}
