
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

const int MAXN = 21234;

int n, m, k;
int s[MAXN][200];
int v[200];

int main (){
	int x, y;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	for(int a=0;a<n;a++){
		for(int i=0;i<x;i++){
			scanf("%d", &s[a][i]);	
		}
	}
	for(int a=0;a<m;a++){
		for(int i=0;i<x;i++){
			int c;
			scanf("%d", &c);
			v[i] = max(v[i], c);
		}
	}
	for(int i=0;i<x;i++){
		v[i] = y - v[i];
	}
	for(int a=0;a<n;a++){
		for(int i=0;i<x;i++){
			printf("%d ", min(s[a][i], v[i]));
		}
		puts("");
	}
}
