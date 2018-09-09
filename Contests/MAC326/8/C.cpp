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

const int MAXN = 212;

int n, m, k;
int s[MAXN], p[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool is(){
	for(int a=0;a<n;a++){
		if(p[a] != p[p[a]]) return false;
	}
	return true;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a]--;
		p[a] = s[a];
	}
	int cnt = 1;
	while(1){
		if(is()){
			printf("%d\n", cnt);
			return 0;
		}
		for(int a=0;a<n;a++)
			p[a] = s[p[a]];	
		cnt++;
	}
}

