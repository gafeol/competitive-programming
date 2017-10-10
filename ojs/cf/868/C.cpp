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
int s[MAXN];

int mrk[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	int res = 0;
	for(int a=0;a<n;a++){
		int bm = 0;
		for(int b=0;b<k;b++){
			scanf("%d", s+b);	
			bm *= 2;
			bm += s[b];
		}
		mrk[bm] = 1;
		for(int b=0;b<(1<<k);b++){
			if(mrk[b] && (b&bm) == 0){
				res = 1;
			}
		}
	}
	if(res)
		puts("YES");
	else
		puts("NO");
}

