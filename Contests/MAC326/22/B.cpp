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
char s[MAXN];

int val(int i, int j){
	if(i == j){
		return s[i]-'0';
	}
	if(s[i] == '0' || j - i + 1 >= 8)
		return -3000000;

	int x = 0;

	while(i <= j){
		x *= 10;
		x += s[i]-'0';
		i++;
	}

	if(x > 1000000)
		x = -3000000;
	return x;
}

int main (){
	scanf(" %s", s);
	n = strlen(s);

	int ans = -1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n-1;j++){
			if(ans < val(0, i) + val(i+1, j) + val(j+1, n-1))
				ans = val(0, i) + val(i+1, j) + val(j+1, n-1);
		}
	}
	printf("%d\n", ans);
}

