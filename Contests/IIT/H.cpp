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

int n;
ll k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


vector<int> X;

int bit[MAXN];

void upd(int i, int val){
	i += 2;
	while(i < MAXN){
		bit[i] += val;
		i += (i&-i);
	}
}

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

int main (){
	scanf("%d%lld", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		X.pb(s[a]);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for(int a=0;a<n;a++){
		s[a] = lower_bound(X.begin(), X.end(), s[a]) - X.begin();
	}
	int i = 0, j = 0;
	ll inv = 0;
	ll ans = 0;
	while(i < n){
		while(j <= i || (inv < k && j < n)){
			ll add = qry(MAXN-10) - qry(s[j]);
			inv += add;
			upd(s[j], 1);
			j++;	
		}
		if(inv >= k){
			ans += (ll)(n-j+1);
		}
		inv -= (ll)qry(s[i]-1);
		upd(s[i], -1);
		i++;
	}
	printf("%lld\n", ans);
}

