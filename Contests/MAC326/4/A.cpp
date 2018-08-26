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

const int MAXN = 1123;

int n, m, k;
int s[MAXN];

ll mn[MAXN], off[MAXN];

int has[MAXN], cnt[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<n;a++)
			scanf("%lld", mn+a);
		for(int a=0;a<m;a++){
			scanf("%lld %d", off+a, cnt+a);
			has[a] = 0;
		}
		ll sum = 0;
		int hasno = m;
		int hasjob = 0;
		for(int a=0;a<n;a++){
			int mx = -1;
			int imx = -1;
			for(int b=0;b<m;b++){
				char c;
				scanf(" %c", &c);
				if(c == '1' && cnt[b] > 0){
					if(mx < off[b]){
						mx = off[b];
						imx = b;
					}
				}
			}
			if(mx >= mn[a]){
				hasjob++;
				if(has[imx] == 0)
					hasno--;
				has[imx]++;
				cnt[imx]--;
				sum += off[imx];
			}
		}

		printf("%d %lld %d\n", hasjob, sum, hasno);
	}
}

