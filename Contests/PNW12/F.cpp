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

bool z(){
	for(int a=0;a<n;a++){
		if(s[a] != 0) return false;
	}
	return true;
}

int main (){
	scanf("%d", &m);
	for(int b=0;b<m;b++){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		int cnt = 0;
		while(!z() && n > 1){
			for(int a=0;a<n;a++)
				s[a] = s[a+1] - s[a];
			n--;
			cnt++;
		}
		if(z()){
			while(cnt--)
				printf("z");
			printf("ap!\n");
		}
		else{
			if(s[0] > 0)
				puts("*fizzle*");
			else
				puts("*bunny*");
		}
	}
}

