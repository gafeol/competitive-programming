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
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		int ok = 1;
		int z = -1;
		s[n] = 0;
		for(int a=0;a<=n;a++){
			if(s[a] == 0){
				if(z != a-1 && z >= a-3)
					ok = 0;
				z = a;
			}
			if(a == n) break;
			int sum = 0;
			if(a-1>0)
				sum += s[a-1];
			if(a+1 < n)
				sum += s[a+1];
			if(sum < s[a]){
				ok = 0;
			}
		}
		printf("Case #%d: ", tt);
		if(ok)
			puts("Yes");
		else
			puts("No");
	}
}

