#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
pll f[MAXN];
ll s[MAXN];
int acu[MAXN];
int ind[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	ll l;
	scanf("%d%d%lld", &n, &m, &l);
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &f[a].fst, &f[a].snd);
	}
	for(int a=0;a<m;a++){
		ind[a] = a;
		scanf("%lld", &s[a]);
	}
	sort(ind, ind+m, [](int a, int b) { return s[a] < s[b]; });
	sort(s, s+m);
	for(int a=0;a<n;a++){
		int mid = max(0ll, upper_bound(s, s+m, f[a].fst) - s - 1ll);

		int i = 0, j = mid;
		while(i < j){
			int m = (i + j)/2;
			if(l >= abs(f[a].fst-s[m]) + f[a].snd)
				j = m;
			else
				i = m+1;
		}
		if(abs(f[a].fst - s[i]) + f[a].snd > l)
			i++;
		if(abs(f[a].fst - s[i]) + f[a].snd > l)
			continue;
		int L = i;
		j = m-1;
		while(i < j){
			int m = (i+j+1)/2;
			if(l >= abs(f[a].fst - s[m]) + f[a].snd){
				i = m;
			}
			else
				j = m-1;
		}
		int R = i;	
		acu[L]++;
		acu[R+1]--;
	}
	int res[MAXN];
	int ans = 0;
	for(int a=0;a<m;a++){
		ans += acu[a];		
		res[ind[a]] = ans;
	}
	for(int a=0;a<m;a++)
		printf("%d\n", res[a]);
}

