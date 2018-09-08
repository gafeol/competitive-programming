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
ll s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

map<ll,int> ult;

int main (){
	scanf("%d", &n);
	ll som = 0;
	ult[0] = 0; 
	pii res;
	res.snd = INT_MAX;
	for(int a=1;a<=n;a++){
		scanf("%lld", s+a);
		if(s[a] == 0){
			printf("%d %d\n", a, 1);
			return 0;
		}
		som += s[a];
		if(ult.find(som) != ult.end()){
			if(res.snd > a - ult[som]){
				res.snd = a - ult[som];
				res.fst = ult[som]+1;
			}
		}
		ult[som] = a;
	}
	if(res.snd != INT_MAX)
		printf("%d %d\n", res.fst, res.snd);
	else
		puts("-1");
}

