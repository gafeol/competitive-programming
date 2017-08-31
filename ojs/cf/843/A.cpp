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
int s[MAXN], ind[MAXN];
int mrk[MAXN];

bool cmp(int a, int b){
	return (s[a] < s[b]);
}

int deg;
vector<int> c[MAXN];

void go(int u){
	if(mrk[u]) return;
	mrk[u] = 1;
	c[deg].pb(u);
	go(ind[u]);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		ind[a] = a;
	}
	sort(ind, ind+n, cmp);

	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		go(a);
		deg++;
	}
	printf("%d\n", deg);
	for(int a=0;a<deg;a++){
		printf("%d ", (int)c[a].size());
		for(int u: c[a]){
			printf("%d ", u+1);
		}
		puts("");

	}
}

