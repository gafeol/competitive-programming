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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100345, SQRT = 400;

int n, m, k;
int s[MAXN];
int x[MAXN];
int xs[SQRT];
int r;

unordered_map<int, int> cnt[SQRT];

int main (){
	scanf("%d%d", &n, &m);
	r = sqrt(n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(a%r == 0)
			x[a] = s[a];		
		else
			x[a] = (s[a]^x[a-1]);
		cnt[a/r][x[a]]++;
		xs[a/r] ^= s[a];
	}
	for(int a=0;a<m;a++){
		int t, i;
		scanf("%d %d %d", &t, &i, &k);
		i--;
		if(t == 1){
			xs[i/r] ^= (s[i]^k);
			for(int j=i;j<min(n, (i/r + 1)*r);j++){
				cnt[j/r][x[j]]--;
				x[j] ^= (s[i]^k);
				cnt[j/r][x[j]]++;
			}
			s[i] = k;
		}
		else{
			int bef = 0;
			int ans = 0;
			for(int is = 0;is < min(n/r + 1, i/r);is++){
				ans += cnt[is][bef^k];
				bef ^= xs[is];
			}
			for(int j = (i/r)*r; j <= min(n-1, i);j++){
				if((bef^x[j]) == k){
					ans++;
				}
			}
			printf("%d\n", ans);
		}
	}
}

