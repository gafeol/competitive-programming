#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
string s[MAXN];

int deg, has[MAXN];

map<char, int> adj[MAXN];
multiset<int> q[MAXN];
int off[MAXN];


int nxt(int u, char c){
	if(adj[u].find(c) == adj[u].end())
		adj[u][c] = ++deg;
	return adj[u][c];
}

void add(int i){
	int u = 0;
	for(char c: s[i]){
		u = nxt(u, c);
	}
	has[u] = i;
	debug("has[%d] = %d\n", u, i);
}

void print(int i){
	return ;
	debug("PRINT %d: ", i);
	for(auto it: q[i]){
		debug("%d ", it);
	}
	debug("\n");
}

void join(int i, int j){
	if(q[j].empty()) return ;
	if(q[i].empty()){
		q[i] = q[j];
		off[i] = off[j];
		return ;
	}
	debug("join i %d j %d\n", i, j);
	print(i);
	print(j);
	if(q[i].size() < q[j].size()){
		debug("enter 1\npre\n");
		print(j);
		for(auto u: q[i]){
			debug("insere %d+%d-%d\n", u, off[i], off[j]);
			q[j].insert(u+off[i]-off[j]);
		}
		debug("j %d\n", j);
		print(j);
		q[i] = q[j];
		off[i] = off[j];
	}
	else{
		debug("enter 2\n");
		for(auto u: q[j])
			q[i].insert(u+off[j]-off[i]);
	}
	debug("pos join\n");
	print(i);
}

void go(int u){
	debug("go %d\n", u);
	for(auto it: adj[u]){
		debug("nxt %c %d\n", it.fst, it.snd);
		go(it.snd);
		off[it.snd]++;
		debug("join u %d it snd %d\n", u, it.snd);
		print(u);
		print(it.snd);
		join(u, it.snd);
	}
	if(has[u] != -1){
		debug("q[%d] insere %d\n", u, -off[u]);
		q[u].insert(-off[u]);
	}
	else{
		int mx = *q[u].rbegin();
		debug("u %d mx %d\n", u, mx);
		q[u].erase(q[u].find(mx));
		debug("insere %d\n", -off[u]);
		q[u].insert(-off[u]);
	}
	print(u);
}

int main (){
	memset(has, -1, sizeof(has));
	has[0] = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		cin >> s[a];
		add(a);
	}
	go(0);
	int ans = 0;
	for(auto a: q[0]){
		ans += a+off[0];
	}
	printf("%d\n", ans);
}

