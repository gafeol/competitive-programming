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
ll s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

ll mn[MAXN];
ll sum[MAXN], dp[MAXN];

ll go(int i){
	ll &r = dp[i];
	if(r != -1) return r;
	if(i >= n) return r = 0;
	return r = min(sum[i] - mn[i] + go(i+k), go(i+1) + s[i]);	
}

multiset<ll> q;

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++)
		scanf("%lld", s+a);
	ll sm = 0;
	for(int a=0;a<min(k, n);a++){
		q.insert(s[a]);
		sm += s[a];
	}
	for(int a=0;a+k-1<n;a++){
		mn[a] = *q.begin();	
		sum[a] = sm;
		sm = sm - s[a] + s[a+k];
		q.erase(q.find(s[a]));
		q.insert(s[a+k]);
	//	printf("a %d mn %lld sum %lld\n", a, mn[a], sum[a]);
	}
	for(int a=n-k+1;a<n;a++){
		sum[a] = sm;
		sm -= s[a];
		//printf("a %d mn %lld sum %lld\n", a, mn[a], sum[a]);
	}
	printf("%lld\n", go(0));
}

