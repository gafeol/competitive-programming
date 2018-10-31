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

const int MAXN = 1123456;

int n, m, k;
char s[MAXN];

int main (){
	scanf(" %s", s);
	map<char, char> ans;
	ans['R'] = 'S';
	ans['B'] = 'K';
	ans['L'] = 'H';
	n = strlen(s);
	for(int i=0;i<n;i++){
		if(i + 2 < n && s[i] != s[i+2] && s[i] != s[i+1] && s[i+1] != s[i+2]){
			printf("C");
			i+=2;
			continue;	
		}
		printf("%c", ans[s[i]]);
	}
	puts("");

}

