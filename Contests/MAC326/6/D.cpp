#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#define div sdasads

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
	//	write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1000056;
const int MAXX = 10000007;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> div[MAXX];

int deg[MAXN];
int tempo;
set<int> has[MAXX];
int th[MAXX];
set<int> pos;

int res[MAXN];

void atu(int d){
	if(th[d] != tempo){
		th[d] = tempo;
		has[d].clear();
	}
}

void check(){
/*	for(auto it: pos){
		for(int d: div[s[it]]){
			if(has[d].size() > 1)
				assert(false);
		}
	}
	*/
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

void rmv(int i){
	check();
	if(deg[i] == 0)
		pos.erase(i);
	deg[i] = 0;
	for(int d: div[s[i]]){
		atu(d);
		has[d].erase(i);
		if(has[d].size() == 1){
			int o = *has[d].begin();
			deg[o]--;
			if(deg[o] == 0)
				pos.insert(o);
		}
	}
	check();
}

void add(int i){
	check();
	debug("add", i);
	assert(deg[i] == 0);
	for(int d: div[s[i]]){
		atu(d);
		if(!has[d].empty())
			deg[i]++;
		if(has[d].size() == 1){
			int o = *has[d].begin();
			if(deg[o] == 0)
				pos.erase(o);
			deg[o]++;
		}
		has[d].insert(i);
	}
	if(deg[i] == 0)
		pos.insert(i);
	check();
}

void clear(){
	pos.clear();

	tempo++;
}

void go(int i, int j, int bef){
	if(i > j) return ;
	if(i == j){
		res[i] = bef;
		return ;
	}
	if(pos.empty()){
		puts("impossible");
		exit(0);
	}
	int m = *pos.begin();
	res[m] = bef;
	int l = m - i;		
	int r = j - m;
	if(l > r){
		for(int a=m;a<=j;a++)
			rmv(a);
		go(i, m-1, m+1);	
		clear();
		for(int a=m+1;a<=j;a++)
			add(a);
		go(m+1, j, m+1);
	}
	else{
		for(int a=i;a<=m;a++)
			rmv(a);
		go(m+1, j, m+1);
		clear();
		for(int a=i;a<m;a++)
			add(a);
		go(i, m-1, m+1);
	}
}

int mrk[MAXX];
int npri[MAXX];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		mrk[s[a]] = 1;
	}
	for(int i=2;i< MAXX;i++){
		if(npri[i]) continue;
		if(mrk[i])
			div[i].pb(i);
		for(ll b = 2; ((ll)i)*b < MAXX;b++){
			npri[b*i] = 1;
			if(mrk[b*i])
				div[b*i].pb(i);
		}
	}
	for(int a=0;a<n;a++)
		add(a);
	go(0, n-1, 0);
	for(int a=0;a<n;a++)
		printf("%d ", res[a]);
	puts("");
}
