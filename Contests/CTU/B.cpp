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

int n, m;
ll k;
ll s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	while(scanf("%d%lld", &n, &k)!= EOF){

		for(int a=0;a<n;a++)
			scanf("%lld", s+a);
		double i = 0, j = 1e9;
		while(j - i > 1e-8){
			double m = (i + j)/2.;		
			double sob = 0;
			int ok = 0;
			for(int a=0;a<n;a++){
				double t = m*k - s[a];	
			if(sob + m*k - s[a] >= 0.)
					ok = 1;
				else
					ok = 0;
				sob = max(0., sob + t);
			}
			if(ok)
				j = m;	
			else
				i = m;
		}
		printf("%.10f ", (i+j)/2.);

		i = 0, j = 1e9;
		while(j - i > 1e-8){
			double m = (i + j)/2.;		
			double sob = 0;
			int ok = 1;
			for(int a=0;a<n;a++){
				double t = m*k - s[a];	
				if(sob + m*k - s[a] < 0.)
					ok = 0;
				sob = max(0., sob + t);
			}
			if(ok)
				j = m;	
			else
				i = m;
		}
		printf("%.10f\n", (i+j)/2.);
	}
}

