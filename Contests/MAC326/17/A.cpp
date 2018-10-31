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

long double A, B, C;

long double go(){
	long double xmax = -B/((long double)2.*A);
	xmax = max(xmax, (long double)0.);
	return A*(xmax*xmax) + B*xmax + (long double)C;
}


int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		long double mx = DBL_MIN;
		int imx;
		for(int a=0;a<n;a++){
			scanf(" %Lf %Lf %Lf", &A, &B, &C);
			A *= -1;
			if(mx < go()){
				mx = go();
				imx = a;	
			}
		}
		printf("%d\n", imx+1);
	}
}

