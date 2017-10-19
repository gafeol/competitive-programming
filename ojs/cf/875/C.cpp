
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
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;

int mrk[MAXN], proi[MAXN];

vector<int> s[MAXN], adj[MAXN], res, ans;

int fodeu;

void go(int u){
	ans.pb(u);
	mrk[u] = 1;
	if(proi[u]) fodeu = 1;
	for(int nxt: adj[u]){
		if(!mrk[nxt])
			go(nxt);
	}
}

void cmp(int i){
	int j = i + 1;
	int sz = min(s[i].size(), s[j].size());
	debug("cmp %d\n", i);
	for(int a=0;a<sz;a++){
		if(s[i][a] != s[j][a]){
			if(s[i][a] < s[j][a]){
				adj[s[j][a]].pb(s[i][a]);
				debug("%d -> %d\n", s[j][a], s[i][a]);
			}
			else{
				res.pb(s[i][a]);
				proi[s[j][a]] = 1;
				debug("res pb %d\nproi %d\n", s[i][a], s[j][a]);
			}
			return ;
		}
	}
	if(s[i].size() > s[j].size())
		fodeu = 1;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		int l;
		scanf("%d", &l);
		while(l--){
			int x;
			scanf("%d", &x);
			s[a].pb(x);
		}
	}
	for(int a=0;a<n-1;a++){
		cmp(a);
	}
	for(int u: res){
		if(!mrk[u])
			go(u);
	}
	if(fodeu)
		puts("No");
	else{
		puts("Yes");
		printf("%d\n", (int)ans.size());
		for(int u: ans)
			printf("%d ", u);
		puts("");
	}
}

