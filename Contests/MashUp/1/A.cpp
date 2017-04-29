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

const int MAXN = 2123456;

int n, m, k;
set<int> s[MAXN];
int v[MAXN];
int N, F;
int A, B, C, M;

int main (){
	scanf("%d %d", &N, &F);
	scanf("%d %d %d", &A, &B, &C);
	v[1] = A;
	s[A].insert(1);
	for(int i = 2; i <= N; i++) { 
		v[i] = (v[i-1]*B + C) % F;
		s[v[i]].insert(i);
	}
	scanf("%d", &M);
	int u,v;
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		if(s[v].find(u) != s[v].end())
			s[v].erase(u);
		int i,j;
		if(s[v].lower_bound(u) == s[v].begin())
			printf("%d\n", N);
		else if(s[v].lower_bound(u) == s[v].end()) {
			i = *(s[v].lower_bound(u)--);
			j = *(s[v].lower_bound(u));
			printf("%d %d\n", u-i,j-u);
		}
	}
	return 0;
}
