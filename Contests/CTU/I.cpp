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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii s[MAXN];

bool cmp(pii a, pii b){
	return a.fst +a.snd < b.fst + b.snd;
}

bool cmp2(pii a, pii b){
	return a.fst-a.snd < b.fst-b.snd;
}


int main (){
	while(scanf("%d", &n)!= EOF){
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			s[a] = pii(i, j);
		}
		if(n == 1){
			puts("0");
			continue;
		}
		sort(s, s+n, cmp);
		int i = 0;
		ll res = 0;
		for(int j=0;j<n;j++){
			while(s[i].fst+s[i].snd != s[j].fst + s[j].snd)
				i++;
			res += 2ll*((ll)j - i);
		}
		sort(s, s+n, cmp2);
		i = 0;
		for(int j=0;j<n;j++){
			while(s[i].fst-s[i].snd != s[j].fst - s[j].snd)
				i++;
			res += 2ll*((ll)j - i);
		}
		double ans = ((double)res)/(((ll)n)*(n));
		printf("%.15f\n", ans);
	}
}

