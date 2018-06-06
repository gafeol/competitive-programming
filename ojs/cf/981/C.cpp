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
int s[MAXN], deg[MAXN];

vector<int> adj[MAXN];
vector<pii> ans;

int main (){
	scanf("%d", &n);
	int ok = 1;
	for(int a=1;a<n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
		deg[i]++;
		deg[j]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i] > 2){
			if(k != 0)
				ok = 0;
			k = i;
		}
	}
	if(!ok){
		puts("No");
		return 0;
	}
	puts("Yes");
	vector<int> f;
	for(int a=1;a<=n;a++){
		if(deg[a] == 1)
			f.pb(a);

	}
	if(k != 0){
		for(int a=1;a<=n;a++){
			if(deg[a] == 1)
				ans.pb(pii(k, a));
		}
	}
	else{
		assert(f.size() == 2);
		ans.pb(pii(f[0], f[1]));
	}
	printf("%d\n", (int)ans.size());
	for(pii p: ans)
		printf("%d %d\n", p.fst, p.snd);
}

