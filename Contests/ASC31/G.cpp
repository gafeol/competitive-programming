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
const ll modn3 = 988619503;
inline ll mod(ll x) { return x % modn; }
inline ll mod2(ll x) { return x % modn2; }
inline ll mod3(ll x) { return x % modn3; }

const int MAXN = 4003;

int n, m, k;
char s[MAXN];


#include <bits/stdc++.h>
using namespace std;

namespace sf {
const int NS = 2;
const int N = 4003*10 * 2;

int cn, cd, ns, en = 1, lst;
string S[NS]; int si = -1;
/* sufn[si][i] no do sufixo S[si][i...] */
vector<int> sufn[N];

struct node {
	int l, r, si;
	int p, suf;
	map<char, int> adj;
	node() : l(0), r(-1), suf(0), p(0) {}
	node(int L, int R, int S, int P) : l(L), r(R), si(S), p(P) {}
	inline int len() { return r - l + 1; }
	inline int operator[](int i) { return S[si][l + i]; }
	inline int& operator()(char c) { return adj[c]; }
} t[N];

inline int new_node(int L, int R, int S, int P) {
	t[en] = node(L, R, S, P);
	return en++;
}

void add_string(string s) {
	s += '$';
	S[++si] = s;
	sufn[si].resize(s.size() + 1);
	cn = cd = 0;
	int i = 0; const int n = s.size();
	for(int j = 0; j < n; j++)
		for(; i <= j; i++) {
			if(cd == t[cn].len() && t[cn](s[j]))
				cn = t[cn](s[j]), cd = 0;
			if(cd < t[cn].len() && t[cn][cd] == s[j]) {
				cd++;
				if(j < s.size() - 1) break;
				else {
					if(i) t[lst].suf = cn;
					for(; i <= j; i++) {
						sufn[si][i] = cn;
						cn = t[cn].suf;
					}
				}
			} else if(cd == t[cn].len()) {
				sufn[si][i] = en;
				if(i) t[lst].suf = en; lst = en;
				t[cn](s[j]) = new_node(j, n - 1, si, cn);
				cn = t[cn].suf;
				cd = t[cn].len();
			} else {
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
				t[t[cn].p](t[cn][0]) = mid;
				if(ns) t[ns].suf = mid;
				if(i) t[lst].suf = en; lst = en;
				sufn[si][i] = en;
				t[mid](s[j]) = new_node(j, n - 1, si, mid);
				t[mid](t[cn][cd]) = cn;
				t[cn].p = mid; t[cn].l += cd;
				cn = t[mid].p;
				int g = cn? j - cd : i + 1;
				cn = t[cn].suf;
				while(g < j && g + t[t[cn](S[si][g])].len() <= j)
					cn = t[cn](S[si][g]), g += t[cn].len();
				if(g == j)
					ns = 0, t[mid].suf = cn, cd = t[cn].len();
				else
					ns = mid, cn = t[cn](S[si][g]), cd = j - g;
			}
		}
}
};


unordered_map<ull, int> qtd;

int main (){
	freopen("pattern.in", "r", stdin);
	freopen("pattern.out", "w", stdout);
	scanf(" %s", s);
	sf::add_string(s);
	n = strlen(s);
	ll res = 0;
	int ires = 0;
	for(int i=0;i<n;i++){
		int let[30];
		memset(let, 0, sizeof(let));
		int mrk = 0;
		ull h = 0, h2 = 0, h3  =0;
		for(int j=i;j<n;j++){
			if(j - i + 1 > n/2 + 2) break;
			if(let[s[j]-'a'] == 0)
				let[s[j]-'a'] = ++mrk;
			int l = let[s[j]-'a'];
			h  = h*31 + l;
			//h2 = mod2(h2*29);
			//h3 = mod3(h3*37);
			//h2= mod2(h2+ l);
			//h3= mod3(h3+l);
			//tuple<ll, ll, ll> t = {h, h2, h3};
			qtd[h]++;
			if(res < ((ll)j-i+1)*qtd[h]){
				res = ((ll)j-i+1)*qtd[h];
				ires = i;
			}
		}
	}
	int i = ires;
	int let[30];
	memset(let, 0, sizeof(let));
	ull h  = 0;
	int mrk = 0;
	for(int j=i;j<n;j++){
		if(let[s[j]-'a'] == 0)
			let[s[j]-'a'] = ++mrk;
		int l = let[s[j]-'a'];
		printf("%c", 'a'+l-1);
		h  = h*31 + l;
		//h2 = mod2(h2*29);
		//h3 = mod3(h3*37);
		//h2= mod2(h2+ l);
		//h3= mod3(h3+l);
		//tuple<ll, ll, ll> t = {h, h2, h3};
		ll val = ((ll)j-i+1)*qtd[h];
		if(val == res){
			puts("");
			return 0;
		}
	}
}

