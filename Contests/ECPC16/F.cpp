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
ll L[MAXN], R[MAXN];
ll p[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

pii s[MAXN];

int d(int t, pii a){
	if(t == 0)
		return a.fst + a.snd;
	else
		return a.fst - a.snd;
}

bool cmp(int a, int b){
	return (s[a].fst + s[a].snd < s[b].fst + s[b].snd);
}

bool cmp2(int a, int b){
	return d(1, s[a]) < d(1, s[b]);
}

bool cmp3(pll a, pll b){
	return (a.snd < b.snd);
}

vector<pll> e;

void add(int x){
	e.pb(pll(L[x], R[x]));
}

int ans;
int ind[MAXN];

void sweep(){
	sort(e.begin(), e.end(), cmp3);
	pll u = e[0];
	int res = 1;
	//printf("ev %d %d\n", u.fst, u.snd);
	for(int i=1;i<e.size();i++){
		pll ev = e[i];
		if(ev.fst > u.snd){
			res++;
			u = ev;
			//printf("ev %d %d\n", u.fst, u.snd);
		}
	}
	//printf("ans %d\n", res);
	ans = max(res, ans);
}

int main (){
	freopen("bishops.in", "r", stdin);
	for_tests(t, tt){
		ans = 0;
		int b;
		scanf("%d%d%d", &b, &n, &k);
		for(int a=0;a<n;a++){
			ind[a] = a;
			int i, j;
			scanf("%d %d %lld",  &i, &j, p+a);
			s[a] = pii(i, j);
			L[a] = (ll)j - p[a]*p[a] + 1ll;
			R[a] = j + p[a]*p[a] -1ll + (ll)k;
			//printf("A %d L %lld R %lld\n", a, L[a], R[a]);
		}
		sort(ind, ind+n, cmp);
		int x = 0;
		while(x < n){
			int ini = x;
			//printf("diag %d (%d): ", ini, d(0, s[ind[x]]));
			e.clear();
			while(x < n && d(0, s[ind[ini]]) == d(0, s[ind[x]])){
				//printf(" %d (%d %d)", ind[x], s[ind[x]].fst, s[ind[x]].snd);
				add(ind[x]);	
				x++;
			}
			//puts("");
			sweep();
		}
		sort(ind, ind+n, cmp2);
		x = 0;
		while(x < n){
			int ini = x;
			//nprintf("diag %d (%d): ", ini, d(1, s[ind[ini]]));
			e.clear();
			while(x < n && d(1, s[ind[ini]]) == d(1, s[ind[x]])){
				//printf(" %d (%d %d)", ind[x], s[ind[x]].fst, s[ind[x]].snd);
				add(ind[x]);	
				x++;
			}
			//puts("");
			sweep();
		}
		printf("%d\n", ans);
	}
}

