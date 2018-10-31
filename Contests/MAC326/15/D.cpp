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
const ll modn2 = 1000000009;
inline ll mod2(ll x) { return x % modn2; }

const int MAXN = 14;

int n, m, k;
int ac[MAXN];

char pal[40];
int s[MAXN][2];

map<pll, int> cnt, BM;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

inline void print(int bm, int t){
	stack<int> res;
	while(t--){
		res.push((bm&1));
		bm = (bm >> 1);
	}
	while(!res.empty()){
		printf("%d", res.top());
		res.pop();
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		int tam = m/2;
		for(int a=0;a<n;a++){
			scanf(" %s %d", pal, ac+a);
			s[a][0] = s[a][1] = 0;
			for(int b=0;b<m;b++){
				s[a][(b >= tam)] = (s[a][(b>=tam)] << 1);
				s[a][(b >= tam)] += pal[b]-'0';
			}
		}

		cnt.clear();
		for(int bm=0;bm<(1<<tam);bm++){
			pll h;
			h.fst = 0;
			h.snd = 0;
			int ok = 1;
			for(int a=0;a<n;a++){
				int pac = tam - __builtin_popcount((s[a][0]^bm));	
				int nd = ac[a] - pac;
				h.fst = mod(h.fst*(m+1ll)+nd);
				h.snd = mod2(h.snd*(m+1ll)+nd);
				if(nd < 0){
					ok = 0;
					break;
				}
			}
			if(!ok) continue;
			cnt[h]++;
			BM[h] = bm;
		}

		tam = m - tam;
		ll res = 0;

		int A, B;

		for(int bm=0;bm<(1<<tam);bm++){
			//printf("bm %d\n", bm);
			pll h = pll(0,0);
			int ok = 1;
			ll has;
			for(int a=0;a<n;a++){
				int pac = tam - __builtin_popcount((s[a][1]^bm));	
				h.fst = mod(h.fst*(m+1ll)+pac);
				h.snd = mod2(h.snd*(m+1ll)+pac);
				if(pac >  ac[a]){
					ok = 0;
					break;
				}
			}
			if(!ok) continue;	

			res += (ll)cnt[h];
			if(res == 1 && cnt[h] == 1){
				A = BM[h];
				B = bm;
			}
		}
		if(res != 1)
			printf("%lld solutions\n", res);
		else{
			int ta = m/2;
			print(A, ta);
			print(B, m - ta);
			puts("");
		}

	}
}
