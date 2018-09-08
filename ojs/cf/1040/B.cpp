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
	scanf("%d%d", &n, &k);
	// k > n 
	int res = INT_MAX, ires = 0;
	for(int a=0;a<=k && a < n;a++){
		int ans = 1;
		int sob = n - a - 1 - k;	
		if(sob > 0){
			ans += sob/(2*k+1);
			int r = sob%(2*k+1);
			if(r > 0 && r < k+1)
				ans = INT_MAX;
			else if(r > 0)
				ans++;
		}	
		if(res > ans){
			res = ans;
			ires = a;
		}
	}
	printf("%d\n", res);
	int i = ires;
	while(i < n){
		printf("%d ", i+1);
		i += 2*k + 1;
	}
	puts("");
}


