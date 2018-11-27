#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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

int n;
ll s[MAXN];
ll p, q;

int ind[MAXN];

bool cmp(int a, int b){
	return (s[a] < s[b]);
}


pll cf(ll a, ll b, ll c){
	return {a*a + b*b - c*c, 2ll*a*b};		
}
bool cp(ll a, ll b, ll c){
	pll co = cf(a, b, c);
	return co.fst*q >= co.snd*p;
}

bool men(pll a, pll b){
	return a.fst*b.snd < a.snd*b.fst;
}

int inv[MAXN];

set<pli> st;

int main (){
	for_tests(t, tt){
		st.clear();
		scanf("%d%lld%lld", &n, &p, &q);
		for(int a=0;a<n;a++){
			ind[a] = a;
			scanf("%lld", s+a);
		}
		sort(ind, ind+n, cmp);
		for(int a=0;a<n;a++)
			st.insert({s[ind[a]], a});

		pll res = {2, 1};
		tuple<int, int, int> ires = {-1, -1, -1};
		pli olda = {-1, -1}, oldb;
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				if(olda.snd != -1){
					st.insert(olda);
					st.insert(oldb);
				}
				ll A = s[a], B = s[b];
				st.erase({A, a});
				st.erase({B, b});
				olda = {A, a};
				oldb = {B, b};
				if(st.lower_bound({A + B, -1}) == st.begin()) continue;
				int fim = (--st.lower_bound({A + B, -1}))->snd;

				if(st.upper_bound({abs(B-A), INT_MAX}) == st.end()) continue;
				int beg = (st.upper_bound({abs(B - A), INT_MAX}))->snd;

				if(beg > fim) continue;

				int i = beg;
				int j = fim;
				while(i < j){
					int m = (i + j + 1)/2;
					ll C = s[ind[m]];
					if(cp(A, B, C))
						i = m;	
					else
						j = m-1;
				}

				while(i >= beg && (ind[i] == a || ind[i] == b)) i--;
				if(i < beg) continue;

				ll C = s[ind[i]];
				if(cp(A, B, C) && men(cf(A, B, C), res)){
					res = cf(A, B, C);
					ires = {a, b, ind[i]};
				}
			}
		}
		int a, b, c;
		tie(a, b, c) = ires;
		if(a == -1){
			puts("-1");
		}
		else{
			printf("%d %d %d\n", a+1, b+1, c+1);
		}
	}
}

