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
const ll modn = 998244353;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

map<ll, ll> cnt;

ll sqtest(ll x){
	ll sq = sqrt(x);
	if(sq*sq == x) return sq;
	if((sq+1)*(sq+1) == x) return sq+1;
	if((sq-1)*(sq-1) == x) return sq-1;
	return -1;
}

ll cbtest(ll x){
	ll cb = cbrt(x);
	if(cb*cb*cb == x) return cb;
	if((cb+1)*(cb+1)*(cb+1) == x) return cb+1;
	if((cb-1)*(cb-1)*(cb-1) == x) return cb-1;
	return -1;
}

ll qdtest(ll x){
	ll sq = sqtest(x);
	if(sq == -1) return -1;
	ll qd = sqtest(sq);
	if(qd == -1) return -1;
	return qd;
}

vector<ll> dp;

vector<ll> pri;
map<ll, bool> in;

void add(ll p){
	if(in.find(p) != in.end()) return ;
	in[p] = true;
	pri.pb(p);
}

ll gcd(ll x, ll y){
	if(x == 0) return y;
	return gcd(y%x, x);
}

void go(ll x){
	ll qdt = qdtest(x);
	if(qdt != -1){
		cnt[qdt] += 4;
		add(qdt);
		return ;
	}
	ll sqt = sqtest(x);
	if(sqt != -1){
		cnt[sqt] += 2;
		add(sqt);
		return ;
	}
	ll cbt = cbtest(x);
	if(cbt != -1){
		cnt[cbt] += 3;
		add(cbt);
		return ;
	}
	dp.pb(x);
}

int foi[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		ll x;
		scanf("%lld", &x);
		go(x);
	}
	for(int i=0;i<dp.size();i++){
		for(int j=i+1;j<dp.size();j++){
			ll gc = gcd(dp[i], dp[j]);
			if(gc < dp[i] && gc > 1){
				ll val = cnt[gc];
				ll q = dp[i]/gc;
				add(gc);
				add(q);
			}
		}
	}

	map<ll, int> sob;
	for(ll x: dp){
		for(ll p: pri){
			if(x%p == 0){
				ll q = x/p;			
				add(q);
			}
		}
	}
	for(ll x: dp){
		int ok = 0;
		for(ll p: pri){
			if(x%p == 0){
				ll q = x/p;			
				cnt[p]++;
				cnt[q]++;
				ok = 1;
				break;
			}
		}
		if(!ok)
			sob[x]++;
	}
	ll res = 1;
	for(auto it: sob)
		res = mod(res * mod((it.snd+1)*(it.snd+1)));	
	for(auto it: cnt){
		res = mod(res * (it.snd + 1));
	}
	printf("%lld\n", res);
}

