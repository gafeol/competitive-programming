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
int c[4];

int main (){
	scanf("%d%d%d", &n, &c[0], &c[1]);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	int res = 0;
	for(int a=0;a<n;a++){
		int mx = max(s[a], s[n-a-1]);
		int mn = min(s[a], s[n-a-1]);
		if(s[a] == 2 && s[n-a-1] == 2){
			s[a] = 0;
			s[n-a-1] = 0;
			res += min(c[0], c[1]);
			if(a != n-a-1)
				res += min(c[0], c[1]);
		}
		else if(s[a] != s[n-a-1]){
			if(mx == 2){
				s[a] = mn;
				s[n-a-1] = mn;
				res += c[mn];
			}
			else{
				puts("-1");
				return 0;
			}
		}

	}
	printf("%d\n", res);
}

