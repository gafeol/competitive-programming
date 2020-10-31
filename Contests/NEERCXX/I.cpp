
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
int fin[300][300];
int par[300][300];
int seen[300][300];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main (){
	int q, p;
	scanf("%d %d %d %d", &n, &m, &q, &p);
	getchar();
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++) {
			char c = getchar();
			if (c == '.') {
				par[i][j] = 0;
			}
			else if (c == '*') {
				par[i][j] = -1;
			}
			else {
				int co = c - 'A' + 1;
				par[i][j] = co*q;
			}
		}
		getchar();
	}
	int t = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (par[i][j] > 0) {
				queue<pair<pair<int, int>, int> > qu;
				qu.push({{i, j}, par[i][j]});
				fin[i][j] += par[i][j];
				seen[i][j] = t+1;
				while(qu.size()) {
					pair<pair<int, int>, int> pt = qu.front();
					qu.pop();
					if (pt.second == 0) continue;
					for (int k=0;k<4;k++) {
						pair<int, int> pn = {pt.first.first+dir[k][0], pt.first.second+dir[k][1]};
						if (pn.first >= 0 && pn.first < n && pn.second >= 0 && pn.second < m && seen[pn.first][pn.second] <= t) {
							int k2 = pt.second/2;
							if (par[pn.first][pn.second] == -1) k2 = 0;
							fin[pn.first][pn.second] += k2;
							qu.push({pn, k2});
							seen[pn.first][pn.second] = t+1;
						}
					}
				}
				t++;
			}
		}
	}
	int count = 0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (par[i][j] >= 0) {
				if (fin[i][j] > p) count++;
			}
		}
	}
	printf("%d\n", count);
}

