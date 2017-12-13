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

const int MAXN = 512345;

int n, m, k;
char t[MAXN];
ll s[MAXN];
ll P[2][MAXN], S[2][MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%lld", s+a);
	for(int a=0;a<n;a++){
		scanf(" %c", t+a);
		if(a != 0){
			P[0][a] = P[0][a-1];
			P[1][a] = P[1][a-1];
		}
		P[0][a] += s[a]*(t[a] == 'A');
		P[1][a] += s[a]*(t[a] == 'B');
	}
	for(int a=n-1;a>=0;a--){
		S[0][a] = S[0][a+1] + s[a]*(t[a] == 'A');
		S[1][a] = S[1][a+1] + s[a]*(t[a] == 'B');
	}
	ll res = max(max(P[0][n-1], P[1][n-1]), max(S[0][0], S[1][0]));
	for(int a=0;a<n;a++){
		res = max(res, S[1][a+1]+P[0][a]);	
		res = max(res, S[0][a+1]+P[1][a]);
	}
	printf("%lld\n", res);
}

