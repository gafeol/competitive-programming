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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

set<int> fr;
int mrk[MAXN];

int has[MAXN];

int cs(int x, int i){
	if(x == 0) return 0;
	return abs(x - i);
}

int main (){
	clock_t clk = clock();
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		s[a] += 3*n;
		mrk[s[a]]++;
	}
	sort(s, s+n);
	for(int a=0;a<5*n;a++){
		if(!mrk[a])
			fr.insert(a);
		else{
			while(mrk[a] > 1){
				int pos = *fr.rbegin();
				has[pos] = a;
				fr.erase(pos);
				mrk[a]--;
			}
			has[a] = a;
		}
	}
	ll res = 0;
	for(int a=0;a<5*n;a++){
		if(has[a]){
			int pos = *fr.upper_bound(has[a]);
			if(abs(pos - has[a]) <  abs(has[a] - a)){
				has[pos] = has[a];								
				has[a] = 0;
				fr.erase(pos);
				fr.insert(a);
			}
		}
	}
	ll ans = LLONG_MAX;

	for(int a=0;a<5*n;a++){
		if(!has[a]) continue;
		res += (ll)abs(has[a] - a);
	}
	ans = res;

	memset(mrk, 0, sizeof(mrk));
	memset(has, 0, sizeof(has));
	fr.clear();
	for(int a=0;a<n;a++){
		s[a] = 3*n + 4*n - s[a];
		mrk[s[a]]++;
	}
	sort(s, s+n);
	for(int a=0;a<5*n;a++){
		if(!mrk[a])
			fr.insert(a);
		else{
			while(mrk[a] > 1){
				int pos = *fr.rbegin();
				has[pos] = a;
				fr.erase(pos);
				mrk[a]--;
			}
			has[a] = a;
		}
	}
	res = 0;
	for(int a=0;a<5*n;a++){
		if(has[a]){
			int pos = *fr.upper_bound(has[a]);
			if(abs(pos - has[a]) <  abs(has[a] - a)){
				has[pos] = has[a];								
				has[a] = 0;
				fr.erase(pos);
				fr.insert(a);
			}
		}
	}
	res = 0;
	for(int a=0;a<5*n;a++){
		if(!has[a]) continue;
		res += (ll)abs(has[a] - a);
	}
	ans = min(ans, res);
	printf("%lld\n", ans);
}

