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

queue<pii> q;
ll dp[20][(1<<16)];

void go(){
	for(int a=0;a<n;a++){
		q.push(pii(a, (1<<a)));
		dp[a][(1<<a)] = 1;
	}
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int u = top.fst;
		int bm = top.snd;
		for(int a=0;a<n;a++){
			if(abs(a - u) <= k && !(bm&(1<<a))){
				if(dp[a][(bm|(1<<a))] == 0)
					q.push(pii(a, (bm|(1<<a))));
				dp[a][(bm|(1<<a))] += dp[u][bm];	
			}
		}
	}
}


int main (){
	for_tests(t, tt){
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &k);
		go();
		ll ans = 0;
		for(int a=0;a<n;a++){
			ans += dp[a][(1<<n)-1];
		}
		printf("%lld\n", ans);
	}
}

