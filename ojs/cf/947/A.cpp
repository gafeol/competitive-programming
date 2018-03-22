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

const int MAXN = 1000006;

int n, m, k;
int s[MAXN];
int mrk[MAXN];
int res[MAXN];
int bst[MAXN];

vector<int> p[MAXN];

int main (){
	for(int a=2;a<MAXN;a++){
		if(mrk[a]) continue;
		for(int b=2;a*b<MAXN;b++){
			mrk[a*b] = 1;
			p[a*b].pb(a);
		}
	}
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		int mx = -1; 
		bst[a] = a;
		for(int pri: p[a])
			bst[a] = min(bst[a], a - pri);
	}
	int ans = n-1;
	for(int a=bst[n]+1;a<n;a++){
		ans = min(ans, min(a, bst[a]+1));	
	}
	printf("%d\n", ans);
}

