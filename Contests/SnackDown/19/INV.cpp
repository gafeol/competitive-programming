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
char ori[MAXN];
char s[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		scanf(" %s", s);
		bool ok = 1;
		bool beg = 1;
		int pos = 0;
		memset(ori, 0, sizeof(ori));
		for(int a=0;a<n;a++){
			if(s[a] != '#') beg = false;
			if(beg && s[a] == '#'){
				ori[a] = '#';
				continue;
			}
			if(s[a] == '#'){
				pos = max(pos, a);
				ori[pos] = '#';
				if(pos > n-2){
					ok = false;
					break;
				}
				pos += 2;
			}
		}
		if(!ok){
			puts("-1");
			continue;
		}
		ll ans = 0;
		for(int a=0;a<n;a++){
			ans -= a*(s[a] == '#');
		}
		int cnt = 0;
		for(int a=0;a<n;a++){
			if(ori[a] != '#')
				ori[a] = '.';
			ans += a*(ori[a] == '#') + (a-cnt)*(ori[a] == '#');
			cnt += (ori[a] == '#');
		}
		//printf("%s\n", ori);
		printf("%lld\n", ans);
	}
}

