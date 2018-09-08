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

ll n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	srand(time(NULL));
	scanf("%lld %lld", &n, &k);
	ll i = 1, j = n;
	int ok = 0;
	while(!ok){
		if(j - i < 40){
			ll r = rand()%(j-i+1);
			printf("%lld %lld\n", i+r, i+r); 	
			fflush(stdout);
			char x[10];
			scanf(" %s", x);
			if(x[0] == 'Y')
				return 0;
			else if(x[0] == 'B')
				return 0;
		}
		else{
			ll m = (i + j)/2ll;
			printf("%lld %lld\n", i, m);
			fflush(stdout);
			char x[10];
			scanf(" %s", x);
			if(x[0] == 'Y'){
				if(i == m)
					return 0;
				j = m;		
			}
			else if(x[0] == 'N')
				i = m+1ll;
			else
				return 0;
		}

		i = max(1ll, i-k);
		j = min(n, j+k);
	}
}

