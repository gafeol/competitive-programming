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


int mrk[MAXN];

int main (){
	freopen("bureau.in", "r", stdin);
	freopen("bureau.out", "w", stdout);
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		char pal[10];
		scanf(" %s", pal);
		if(pal[0] == 'd')
			s[a] = 0;
		else
			scanf("%d", &s[a]);
	}
	stack<int> st;
	for(int a=n;a>=1;a--){
		if(mrk[a]) continue;
		mrk[s[a]] = 1;
		st.push(a);
	}
	printf("%d\n", st.size());
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
	puts("");
}

