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

const int MAXN = 512345;

int n, m, k;
char s[MAXN];

int fst[MAXN];
int lst[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	fgets(s, MAXN-10, stdin);
	n = strlen(s);
	n--;
	for(int a=0;a<n;a++){
		if(s[a] == ' '){
			fst[a] = a+1;
			continue;
		}
		if(a == 0 || s[a-1] == ' ')
			fst[a] = a;
		else
			fst[a] = fst[a-1];
	}
	for(int a=n-1;a>=0;a--){
		if(s[a] == ' '){
			lst[a] = a;
			continue;
		}
		if(a == n-1 || s[a+1] == ' ')
			lst[a] = a;
		else
			lst[a] = lst[a+1];
	}

	int A, B;
	scanf("%d%d", &A, &B);
	for(int sz = A;sz <= B;sz++){
		int i = 0;
		int ans = 0;
		while(i < n){
//			printf("i %d sz %d -> ", i, lst[i] - fst[i] + 1);
			if(ans > 0) ans++;
			ans += lst[i] - fst[i] + 1;	
			i += sz;
//			printf("%d (%c) <- ", i, s[i]);
			if(i < n)
				i = fst[i];
//			printf("%d (%c) \n", i, s[i]);
		}
		printf("%d\n", ans);
	}
}

