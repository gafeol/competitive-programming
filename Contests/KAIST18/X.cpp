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

const int MAXN = 1000456;

int n, m, k;
int s[MAXN];

int mrk[MAXN], usa[MAXN];

typedef tuple<int, ll, int> tp;
vector<tuple<int, ll, int> > adj[MAXN];

void go(int u, int d){
	mrk[u] = d;
	for(tp t: adj[u]){
		int v, id;
		ll cus;
		tie(v, cus, id) = t;
		if(!usa[id] || mrk[v]) continue;
		go(v, d+1);
	}
}

ll cs[MAXN];

using ret_t = vector<set<pair<ll, int> > >;
ret_t A, B;
const ll oo = numeric_limits<ll>::max();
ret_t calc(int s){
	ret_t ans(n+1);
	vector<ll> y(n+1, oo);
	for(auto ed: adj[s]){
		int v, _id; ll w;
		tie(v, w, _id) = ed;
		assert(y[v] == oo);
		y[v] = w;
	}
	for(int i=2;i<n;i++){
		if(y[i] == oo) continue;
		for(auto ed: adj[i]){
			int v, _id; ll w;
			tie(v, w, _id) = ed;
			ans[v].insert({y[i] + w, i});
			if(v == s) continue;
			if(ans[v].size() > 3)
				ans[v].erase(*ans[v].rbegin());
		}
	}
	return ans;
}

void print(ll ans){
	if(ans == oo)
		puts("-1");
	else 
		printf("%lld\n", ans);
}

ll getmn(int u){
	ll ans = oo;
	if(!A[u].empty()){
		ans = A[u].begin()->fst;
	}
	return ans;
}

bool valid(int a, int b, int c, int d){
	vector<int> v;
	v.pb(a);v.pb(b);v.pb(c);v.pb(d);
	for(int a=0;a<4;a++){
		for(int b=a+1;b<4;b++){
			if(v[a] == v[b]) 
				return false;
		}
	}
	return true;
}

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=0;a<m;a++){
		int i, j, c;
		scanf("%d%d%d", &i, &j, &c);
		cs[a] = c;
		adj[i].pb({j, c, a});
		adj[j].pb({i, c, a});
	}
	if(m <= 10){
		ll res = oo;
		for(int bm=0;bm<(1<<m);bm++){
			if(__builtin_popcount(bm) != k) continue;
			ll sum = 0;
			for(int i=0;i<m;i++){
				if((bm&(1<<i))){
					usa[i] = 1;
					sum += cs[i];
				}
				else
					usa[i] = 0;
			}
			for(int a=0;a<=n;a++)
				mrk[a] = 0;
			go(1, 1);
			if(mrk[n] == k+1){
				res = min(res, sum); 
			}
		}
		print(res);
	}
	else{ 
		A = calc(1);
		B = calc(n);
		assert(k <= 5);
		if(k == 1){
			ll ans = oo;
			for(auto ar: adj[1]){
				int v, id; ll w;	
				tie(v, w, id) = ar;
				if(v == n)
					ans = min(ans,w);
			}
			print(ans);
		}
		else if(k == 2){
			print(getmn(n));
		}
		else if(k == 3){
			ll ans = oo;
			for(auto ar: adj[n]){
				int v, id; ll w;	
				tie(v, w, id) = ar;
				if(v == 1) continue;
				ll cus = getmn(v); 
				if(cus == oo) continue;
				ans = min(ans, cus + w);
			}
			print(ans);
		}
		else if(k == 4){
			ll ans = oo;
			for(int mid=2;mid<n;mid++){
				for(auto ia: A[mid]){
					for(auto ib: B[mid]){
						if(valid(ia.snd, ib.snd, mid, 1)){
							ans = min(ans, ia.fst + ib.fst);
						}
					}
				}
			}
			print(ans);
		}
		else{
			ll ans = oo;
			for(int mid=2;mid<n;mid++){
				for(auto ar: adj[mid]){
					int v, id; ll w;	
					tie(v, w, id) = ar;
					int mid2 = v;
					if(mid2 == n || mid2 == 1) continue;
					for(auto ia: A[mid]){
						for(auto ib: B[mid2]){
							if(valid(ia.snd, ib.snd, mid, mid2)){
								ans = min(ans, ia.fst + ib.fst + w);
							}
						}
					}
				}
			}
			print(ans);
		}
	}
}

