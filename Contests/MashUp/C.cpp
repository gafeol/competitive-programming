#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define int long long
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;
const int MAXS = 112345;

int n, m, k;
int s[MAXN];

int N,S;
vector<int> adjrev[MAXS], adj[MAXS];
int ways[MAXN];
int path[MAXN];

main (){
	scanf("%lld %lld", &n, &S);
	
	int a,b;
	for(int i = 0; i < S; i++){
		scanf("%lld %lld", &a, &b);
		adjrev[b].push_back(a);
		adj[a].push_back(b);
	}
	ways[n] = 1;
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < adjrev[i].size(); j++) {
			int v = adjrev[i][j];
			ways[v] += ways[i];
		}
	//	printf("%lld\n", ways[i]);
	}
	path[n] = 1;
	for(int i = n-1; i >= 1; i--) {
		int maior = 0;
		for(int j = 0; j < adj[i].size(); j++) {
			int v = adj[i][j];
			maior = max(maior,path[v]);
		}
		path[i] = ways[i] + maior;
	//	printf("%lld\n", path[i]);
	}
	printf("%lld\n",path[1]);
}
