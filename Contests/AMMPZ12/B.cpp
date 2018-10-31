#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

const int MAXN = 1023;

int n, m, k;
ll dp[MAXN][MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> NV;
vector<pii> v[MAXN*MAXN];
ll z[MAXN][MAXN];
int nv[MAXN][MAXN];

ll pt[4];

ll c(int t, pii p){
	int x = p.fst;
	int y = p.snd;
	ll res = dp[p.fst][p.snd];
	if(t == 0){
		res +=  p.fst + p.snd;
	}
	else if(t == 1){
		res += p.fst - p.snd;
	}
	else if(t == 2)
		res += -p.fst + p.snd;
	else
		res += -p.fst - p.snd;
	return res;
}

void go(int k){
	for(int t=0;t<4;t++)
		pt[t] = LLONG_MIN;
	for(int i=0;i<v[k].size();i++){
		for(int t=0;t<4;t++){
			if(pt[t] < c(t, v[k][i])){
				pt[t] = c(t, v[k][i]);
			}
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d",&nv[a][b]); 
			NV.pb(nv[a][b]);
			v[nv[a][b]].pb(pii(a, b));
		}
	}
	sort(NV.begin(), NV.end());
	NV.erase(unique(NV.begin(), NV.end()), NV.end());
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%lld", &z[a][b]);
		}
	}
	ll ans = 0;
	for(pii u: v[NV.back()]){
		dp[u.fst][u.snd] = z[u.fst][u.snd];
		ans = max(ans, dp[u.fst][u.snd]);
	}
	for(int a=NV.size()-2;a>=0;a--){
		if(NV[a] == 0) continue;
		go(NV[a+1]);	
		for(pii p: v[NV[a]]){
			int x = p.fst;
			int y = p.snd;
			ll res = 0;
			dp[x][y] = 0;
			for(int t=0;t<4;t++){
				res = max(res, z[x][y] + pt[t] + c(3 - t, p));	
			}
			dp[x][y] = res;
			ans = max(ans, res);
		}
	}
	printf("%lld\n", ans);
}

