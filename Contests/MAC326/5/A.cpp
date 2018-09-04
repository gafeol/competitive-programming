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

const int MAXN = 71;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char A[MAXN], B[MAXN];


ll idx(char* s){
	int t = 0;
	ll pos = 0;
	for(ll a=0;a<n;a++){
		if(s[a] == '1'){
			if(!t)
				pos += (1ll<<(n-1ll-a));
			t ^= 1;
		}
		else{
			if(t)
				pos += (1ll<<(n-1ll-a));
		}
	}
	//printf("idx %lld\n", pos);
	return pos;
}

int main (){
	scanf("%d", &n);
	scanf(" %s", A);
	scanf(" %s", B);
	printf("%lld\n", max(0ll, idx(B) - idx(A)-1));
}

