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

char pal[MAXN];

int main (){
	scanf(" %s", pal);
	n = strlen(pal);
	for(int a=0;a<n;a++){
		char c = pal[a];
		s[a] = (c == 'b');
	}
	stack<int> ans;
	int t = 1;
	for(int a=n-1;a>=0;a--){
		if(s[a] == t){
			ans.push(0);
			continue;
		}
		ans.push(1);
		t = (t^1);
	}
	while(!ans.empty()){
		printf("%d ", ans.top());
		ans.pop();
	}
	puts("");
}

