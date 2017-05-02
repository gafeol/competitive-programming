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
int d[MAXN], h[MAXN];
int s[2][MAXN], s2[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &d[a]);	
	}
	for(int a=0;a<n;a++){
		scanf("%d", &h[a]);
	}
	for(int a=0;a<2*n;a++){
		if(a != 0){
			s1[a] = s1[a-1];
			s2[a] = s2[a-1];
		}
		s1[a] += h[a%n];
		s2[a] += h[a%n];
	}
	build(0, 
}
