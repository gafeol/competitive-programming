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
	scanf("%d", &n);
	if(n <= 100){
		printf("1\n1\n1 %d\n", n);
		return 0;
	}
	int blsz = n/100;
	double mn = DBL_MAX;
	for(int b=n;n<=1000*b;b--){
		double conta = ((double)b)*ceil(log(b)/log(2)) + ((double)n)*ceil(log(n/b)/log(2));		
		if(conta < mn){
			blsz = b;
			mn = conta;
		}
	}

	printf("2\n");	
	vector<pii> ans;
	for(int a=0;a<n;a+=blsz){
		ans.pb({a+1, min(n, a+1+blsz-1)});
	}
	printf("%d\n", (int)ans.size());
	for(pii p: ans){
		printf("%d %d\n", p.fst, p.snd);
	}
	printf("1\n");
	printf("1 %d\n", n);

}

