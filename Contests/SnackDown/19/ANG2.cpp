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
ll s[MAXN];
ll p, q;

int ind[MAXN];

bool cmp(int a, int b){
	return (s[a] < s[b]);
}

bool valid(ll a, ll b, ll c){
	vector<ll> v(3);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	sort(v.begin(), v.end());
	return ((v[2] - v[1]) < v[0] && v[0] + v[1] > v[2]);
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

int main (){
	for_tests(t, tt){
		scanf("%d%lld%lld", &n, &p, &q);
		for(int a=0;a<n;a++){
			ind[a] = a;
			scanf("%lld", s+a);
		}
		sort(ind, ind+n, cmp);
		pll res = {2, 1};
		tuple<int, int, int> ires = {-1, -1, -1};
		for(int a=0;a<n;a++){
			for(int b=a+1;b<n;b++){
				ll A = s[a], B = s[b];

				int i = 0, j = n-1;
				while(i < j){
					int m = (i + j + 1)/2;	
					ll C = s[ind[m]];
					if(C >= A + B)
						j = m-1;	
					else
						i = m;
				}
				int fim = i;
				while(fim >= 0 && (ind[fim] == a || ind[fim] == b)) fim--;

				if(fim < 0 || s[ind[fim]] >= A + B) continue;

				i = 0; j = n-1;
				while(i < j){
					int m = (i + j)/2;
					ll C = s[ind[m]];
					if(C <= abs(B - A))
						i = m+1;
					else
						j = m;
				}
				int beg = i;
				while(beg < n && (ind[beg] == a || ind[beg] == b)) beg++;

				if(beg >= n || s[ind[beg]] <= abs(B - A)) continue;
				if(beg > fim) continue;

				i = beg;
				j = fim;
				for(int a=i;a<=j;a++){
					assert(valid(A, B, s[ind[a]]));
				}
				while(i < j){
					int m = (i + j + 1)/2;
					ll C = s[ind[m]];
					if(cp(A, B, C))
						i = m;	
					else
						j = m-1;
				}

				while(i >= 0 && (ind[i] == a || ind[i] == b)) i--;
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


