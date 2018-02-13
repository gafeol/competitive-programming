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

const int MAXN = 712;

int n, m, k;
int s[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		int ok = 1;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				scanf("%d", s[a]+b);
			}
		}
		int mx = INT_MAX;
		ll res = 0;
		for(int a=n-1;a>=0;a--){
			int ans = 0;
			for(int i=0;i<n;i++){
				if(s[a][i] < mx)
					ans = max(ans,s[a][i]);
			}
			if(ans == 0){
				puts("-1");
				ok = 0;
				break;
			}
			res += ans;
			mx = ans;
		}
		if(!ok) continue;
		printf("%lld\n", res);
	}

}

