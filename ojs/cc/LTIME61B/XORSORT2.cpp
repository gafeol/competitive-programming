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

const int MAXN = 215;

int n, m, k;
int s[MAXN][MAXN];

int ans[MAXN];

void join(int i){
	for(int a=0;a<m;a++){
		ans[a] = s[i][ans[a]];
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf("%d", &s[a][b]);
				s[a][b]--;
			}
		}
		scanf("%d", &k);
		for(int a=0;a<k;a++){
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			r--;
			for(int b=0;b<m;b++)
				ans[b] = s[l][b];
			for(int i=l+1;i<=r;i++)
				join(i);
			ll res = 0;
			for(int b=0;b<m;b++){
				res += (b+1)*(1+ans[b]);
			}
			printf("%lld\n", res);
		}
	}
}

