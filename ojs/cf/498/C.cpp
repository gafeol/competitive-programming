#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int ll
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m, k, ans, res;
int s[MAXN], criv[112345], v[MAXN], deg[MAXN], dg[MAXN], mrk[MAXN];

vector<int> pri, adj[MAXN];

set<int> p;

const int N = ;
typedef int num;
const num inf = 100000000;
int n, MA[N], MB[N], PB[N], mn[N];
num c[N][N], d[N];

bool S[N], T[N];
int st[N], sn;
num y[N], z[N];

void reset_all() {
	// need to be changed for costs < 0
	for(int i = 0; i < N; i++)
		y[i] = z[i] = num(0);
	int i;
	for(i = 0; i < n; i++)
		MA[i] = MB[i] = -1;
}

bool increase(int b) {
	int a = PB[b];
	while(true) {
		int n_b = MA[a];
		MB[b] = a;
		MA[a] = b;
		if(n_b == -1) break;
		b = n_b;
		a = PB[b];
	}
	return true;
}

// O(n)
bool visit(int a) {
	S[a] = true;
	for(int b = 0; b < n; b++) {
		if(T[b]) continue;
		if(c[a][b] - y[a] - z[b] < d[b]) {
			d[b] = c[a][b] - y[a] - z[b];
			mn[b] = a;
		}
		if(c[a][b] == y[a] + z[b]) {
			T[b] = true;
			PB[b] = a;
			st[sn++] = b;
			if(MB[b] == -1)
				return increase(b);
		}
	}
	return false;
}

// O(n)
bool update_dual() {
	int mb = -1, b;
	for(b = 0; b < n; b++)
		if(!T[b] && (mb == -1 || d[b] < d[mb]))
			mb = b;
	num e = d[mb];
	for(b = 0; b < n; b++)
		if(T[b]) z[b] -= e;
		else d[b] -= e;
	for(int a = 0; a < n; a++)
		if(S[a]) y[a] += e;
	PB[mb] = mn[mb];
	if(MB[mb] == -1) return increase(mb);
	st[sn++] = mb;
	T[mb] = true;
	return false;
}

// O(n^2)
void find_path() {
	int i, a;
	for(a = 0; MA[a] != -1; a++);
	memset(S, 0, sizeof S);
	memset(T, 0, sizeof T);
	for(int i = 0; i < N; i++) d[i] = inf;
	sn = 0;
	if(visit(a)) return;
	while(true) {
		if(sn) { if(visit(MB[st[--sn]])) break; }
		else if(update_dual()) break;
	}
}

num min_match() {
	reset_all();
	for(int i = 0; i < n; i++)
		find_path();
	num all = 0;
	for(int a = 0; a < n; a++)
		all += c[a][MA[a]];
	return all;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	printf("%d\n", min_match());
}

void div(int pr){
	for(int a=1;a<=n;a++){
		mrk[a] = 0;
		deg[a] = dg[a];
		v[a] = 0;
		int val = s[a];
		while(val%pr == 0){
			v[a]++;
			val /= pr;
		}
	}
}

void go(int u){
	mrk[u] = 1;
	for(int nxt: adj[u]){
		int aux = min(v[u], v[nxt]);
		ans += aux;
		v[u] -= aux;
		v[nxt] -= aux;
		if(mrk[nxt]) continue;
		go(nxt);
	}
}

queue<int> q;
main (){
	for(int i=2;i<112345;i++){
		if(criv[i]) continue;
		pri.pb(i);
		for(ll j = i;i * j < 112345;j++){
			criv[i*j] = 1;
		}
	}
	scanf("%lld%lld", &n, &m);
	for(int a=1;a<=n;a++){
		scanf("%lld", &s[a]);
		int val = s[a];
		debug("analisa %lld\n", val);
		for(int pr: pri){
			if(val%pr == 0){
				p.insert(pr);
				debug("eh dividod por %lld\n", pr);
			}
			while(val%pr == 0){
				val /= pr;
			}
		}
		debug("e sobra %lld\n", val);
		if(val != 1)
			p.insert(val);
	}
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%lld %lld", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		dg[j]++;
		dg[i]++;
	}


	while(!p.empty()){
		int pr = *p.begin();
		debug("pr %lld\n", pr);
		p.erase(pr);
		div(pr);
		for(int a=1;a<=n;a++){
			if(v[a] == 0){
				mrk[a] = 1;
				for(int nxt: adj[a]){
					deg[nxt]--;
				}
			}
		}
		for(int a=1;a<=n;a++){
			if(deg[a] <= 1 && !mrk[a]){
				q.push(a);
				mrk[a] = 1;
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int nxt: adj[u]){
				int aux = min(v[u], v[nxt]);
				ans += aux;
				v[u] -= aux;
				v[nxt] -= aux;
				deg[nxt]--;
				if(deg[nxt] <= 1 && mrk[nxt] == 0){
					mrk[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		for(int a=1;a<=n;a++){
			if(mrk[a] == 0){
				go(a);
			}
		}
	}
	printf("%lld\n", ans);
}
