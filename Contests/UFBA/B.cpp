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

const int MAXN = 2123;

int n, m, k;
char s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf(" %s", s);
	n = strlen(s);
	char p[MAXN];
	scanf(" %s", p);
	m = strlen(p);
	int res = 0;
	for(int i=0;i<=n-m;i++){
		bool ok = 1;
		char c[3];
		c[0] = c[1] = 0;
		for(int j=0;j<m;j++){
			if(c[p[j]-'0'] == 0){
				c[p[j]-'0'] = s[i+j];
				continue;
			}
			if(c[p[j]-'0'] != s[i+j]){
				ok = 0;
				break;
			}
		}
		bool ok2 = 1;
		c[0] = c[1] = 0;
		for(int j=0;j<m;j++){
			if(c[p[m-1-j]-'0'] == 0){
				c[p[m-1-j]-'0'] = s[i+j];
				continue;
			}
			if(c[p[m-1-j]-'0'] != s[i+j]){
				ok2 = 0;
				break;
			}
		}
		res += (ok|ok2);
	}
	printf("%d\n", res);
}

