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

int main (){
	freopen("h.in", "r", stdin);
	scanf("%d%d", &m, &n);
	int res = 0;
	for(int a=0;a<=m;a++){
		for(int b=a;b<=m;b++){
			for(int c=b;c<=m;c++){
				ll aa = a*a;
				ll bb = b*b;
				ll cc = c*c;
				for(int i=2;i<=n;i++){
					if(aa + bb != cc)	
						break;
					res++;
					aa *= a;
					bb *= b;
					cc *= c;
				}
				
			}
		}
	}
	printf("%d\n", res);

}

