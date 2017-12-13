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

int n[2], m, k;
pii s[MAXN][2];

int main (){
	for_tests(te, tt){
		scanf("%d%d", &n[0], &n[1]);
		for(int t=0;t<2;t++){
			for(int a=0;a<n[t];a++){
				int x, y;
				scanf("%d %d", &x, &y);
				s[a][t] = pii(x, y);
			}
		}
		for(int i=0;i<n[0];i++){
			for(int t=0;t<2;t++){
				for(int a=0;a<n[t];a++){

				}
			}
		}
	}
}

