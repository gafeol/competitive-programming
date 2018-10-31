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


int n, m, k;
set<int> q;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

int calc(){
	int ans = 0;
	for(auto it: q){
		ans = gcd(ans, it);
	}
	return ans;
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++)
		q.insert(a);	
	int res = 1;
	int lst = 1;
	while(!q.empty()){
		if(lst <= *q.begin() && q.size() <= 3){
			printf("%d ", calc());
			q.erase(q.begin());
			continue;
		}
		printf("%d ", res);
		q.erase(lst);
		lst += res*2; 
		if(lst > n){
			lst = *q.begin();
			res = res*2;
		}
	}
}

