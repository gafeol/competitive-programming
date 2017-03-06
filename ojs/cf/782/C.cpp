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
int s[MAXN], mx;
vector<int> adj[MAXN];

void go(int u, int p){
	int cnt = 1;
	for(int nxt: adj[u]){
		if(nxt == p) continue;	
		while(1){
			if(cnt != s[u] && cnt != s[p])
				break;
			cnt++;
		}
		s[nxt] = cnt;
		go(nxt, u);
		mx = max(mx, cnt);
		cnt++;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	s[1] = 1;
	go(1, n+1);
	printf("%d\n", mx);
	for(int a=1;a<=n;a++){
		printf("%d ", s[a]);
	}
}
