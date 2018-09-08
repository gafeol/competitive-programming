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
const ll modn2 = 1000000009;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}


int ans;

int vec[MAXN];

vector<int> v[MAXN];

map<pll, int> cnt;

int main (){
	scanf("%d%d", &n, &m);
	int ires, res = -1;

	for(int a=0;a<n;a++){
		ll h = 0, h2 = 0;
		int um = 0;
		for(int i=0;i<m;i++){
			h = mod(h*2ll);
			h2 = mod2(h2*2ll);

			char c;
			while(isspace(c = getchar()));
			v[a].pb((c=='1'));
			if(c == '1'){
				um++;
				h = mod(h+1);
				h2 = mod2(h2+1);
			}
		}
		if(um >= 8 && um <= 15){
			int qtd = ++cnt[pll(h, h2)];
			if(qtd > res){
				res = qtd;
				ires = a;
			}
		}
	}
	if(res == -1){
		for(int a=0;a<m;a++){
			printf("%d", (a < 8 ? 1:0));	
		}
	}
	else{
		for(int a=0;a<m;a++)
			printf("%d", v[ires][a]);
	}
	puts("");
}

