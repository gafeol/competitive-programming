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

int n, k;
int mrk[MAXN];

int main (){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		scanf("%d%d", &n, &k);
		int ans = 1;
		for(int a=0;a<n;a++){
			int ok = 0;
			int cnt;
			scanf("%d", &cnt);
			for(int b=0;b<cnt;b++){
				int x;
				scanf("%d", &x);
				if(!mrk[x]){
					ok = 1;
					mrk[x] = 1;
				}
			}
			ans = min(ans, ok);
		}
		int sad = 0;
		for(int a=1;a<=k;a++){
			if(!mrk[a]){
				puts("sad");
				sad = 1;
				break;
			}
		}
		if(sad) continue;
		if(ans)
			puts("all");
		else
			puts("some");
	}
}
