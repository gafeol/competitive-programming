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

int x[MAXN];
int id[MAXN];
int adj[2][MAXN];
int s[2][MAXN];

int res;

vector<int> ans;

void go(int v){
	s[0][0] = v;
	for(int a=0;a<n;a++){
		s[1][a] = v^x[a];
		s[0][adj[1][a]] = v^x[a];
	}
	for(int a=0;a<n;a++)
		if(s[1][a] >= n || s[0][s[1][a]] != a) 
			return ;
	res++;
	if(res == 1){
		for(int a=0;a<n;a++){
			ans.pb(s[0][a]);
		}
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		printf("? 0 %d\n", a);
		fflush(stdout);
		int xo;
		scanf("%d", &xo);
		if(xo == -1) return 0;
		x[a] = xo;
		id[xo] = a;
		if(xo == 0){
			adj[0][0] = a;
			adj[1][a] = 0;
		}
	}
	for(int a=1;a<n;a++){
		printf("? %d %d\n", a, adj[0][0]);	
		fflush(stdout);
		int xo;
		cin >> xo;
		if(xo == -1) return 0;
		adj[0][a] = id[xo];
		adj[1][id[xo]] = a;
	}
	for(int a=0;a<n;a++)
		go(a);
	puts("!");
	fflush(stdout);
	printf("%d\n", res);
	fflush(stdout);
	for(int u: ans){
		printf("%d ", u);
	}
	puts("");
	fflush(stdout);
}

