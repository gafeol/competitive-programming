
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

const int MAXN = 212345, MAXM = 312;

int n, m, k;
int s[MAXM], need[MAXN][MAXM];
set<int> mn[MAXM];

int main (){
	scanf("%d %d %d", &n, &m, &k);
	for(int a=0;a<m;a++){
		scanf("%d", &s[a]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
		}
	}
}

