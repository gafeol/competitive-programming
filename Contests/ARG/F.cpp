
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

int n, m;
pair<int, int> h[MAXN];
pair<int, int> v[MAXN];

int main (){
	int t;
	scanf("%d", &t);
	for (;t--;) {
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int a, b;
			scanf("%d %d", &a, &b);
			h[i] = {a, b};
			v[i] = {-b, a};
		}
		sort(v, v+n);
		sort(h, h+n);
		int resp = 1791791791;
		int g[3] = {0, 0, h[n-1].first};
		for (int i=0;i<n-1;i++) {
			for (int j=i+1;j<n-1;j++) {
				pair<int, int> w[3];
				g[1] = h[j].first;
				g[0] = h[i].first;
				w[0] = pair<int, int>({h[i].second, 0});
				w[1] = pair<int, int>({h[j].second, 1});
				w[2] = pair<int, int>({h[n-1].second, 2});
				for (int k=0;k<n;k++) {
					if (k == i || k == j || k == n-1) continue;
					sort(w, w+3);
					for (int p=0;p<3;p++) {
						if (g[w[p].second] >= v[k].second) {
							w[p].first -= v[k].first;
							break;
						}
					}
				}
				int mx = 0;
				for (int k=0;k<3;k++) {
					mx = max(mx, w[k].first);
				}
				resp = min(resp, mx*(g[0]+g[1]+g[2]));
			}
		}
		printf("%d\n", resp);
	}
}







