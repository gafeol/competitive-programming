
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
int v[MAXN], w[MAXN];
int sum[MAXN], sum2[MAXN];

int main (){
	int t;
	scanf("%d", &t);
	for (;t--;) {
		int x = 1, y = 1;
		scanf("%d %d", &n, &m);
		for(int i=0;i<n-1;i++){
			scanf("%d", &v[i]);
		}
		for(int i=0;i<m-1;i++){
			scanf("%d", &w[i]);
		}
		sort(v, v+n);
		sort(w, w+m);
		for (int i=1;i<n;i++) {
			sum[i] = sum[i-1] + v[i-1];
		}
		for (int i=1;i<m;i++) {
			sum[i] = sum[i-1] + w[i-1];
		}
		int resp = 0;
		while(x != n || y != m) {
			if (x != n && (y==m || x*w[m-y-1] + (y+1)*sum[n-x] < y*v[n-x-1] + (x+1)*sum2[m-y])) {
				x++;
				resp += y*v[n-x-1];
			}
			else {
				y++;
				resp += x*w[m-y-1];
			}
		}
		printf("%d\n", resp);
	}
}

