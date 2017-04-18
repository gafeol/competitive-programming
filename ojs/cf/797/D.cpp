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
int s[MAXN], L[MAXN], R[MAXN], err[MAXN];
int deg[MAXN];
int res;
map<int, int> ok;

void go(int u, int mx, int mn){
	if(u == -1)
		return;
	if(s[u] > mx || s[u] < mn)
		err[u] = 1;
	go(L[u], min(mx, s[u]), mn);
	go(R[u], mx, max(s[u], mn));
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d %d %d", &s[a], &L[a], &R[a]);
		if(L[a] != -1)
			deg[L[a]]++;
		if(R[a] != -1)
			deg[R[a]]++;
	}
	int r;
	for(int a=1;a<=n;a++){
		if(deg[a] == 0)
			r = a;
	}
	go(r, INT_MAX, -1);
	for(int a=1;a<=n;a++){
		if(!err[a])
			ok[s[a]] = 1;
	}
	for(int a=1;a<=n;a++){
		if(err[a] && ok.find(s[a]) == ok.end())
			res++;
	}
	printf("%d\n", res);
	
}
