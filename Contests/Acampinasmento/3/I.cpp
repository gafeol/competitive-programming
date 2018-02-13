#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

vector<int> s[N][5];
int e[N][5];

int tme = 1;
int vis[N];
vector<int> path;
int find(int v, int u, int p, int ini = -1) {
	if (ini == -1) ini = v;
	//printf("%d %d %d %d\n", v, u, p, e[v][p]);
	vis[v] = tme;
	if (v == u) {
		path.push_back(v);
		return 1;
	}
	for (auto a : s[e[v][p]][p]) {
		if (vis[a] < tme) {
			int k = find(a, u, p, ini);
			if (k == 1) {
				path.push_back(v);
				if (v == ini) tme++;
				return 1;
			}
		}
	}
	if (v == ini) tme++;
	return 0;
}

void print(int n) {
	int k = 0;
	map<int, int> m;
	vector<int> resp;
	for (int i = path.size()-1;i>=0; i--) {
		int a = path[i];
		if (m[a] == 0 && a >= 1 && a <= n) resp.push_back(a);
		m[a] = 1;
	}
	printf("%d\n", (int)resp.size());
	for (auto a : resp) {
		printf("%d ", a);
	} printf("\n");
}

int main () {
	int xt, yt, n;
	scanf("%d %d %d", &xt, &yt, &n);
	for (int i=1;i<=n;i++) {
		int x, y, xf, yf;
		scanf("%d %d %d %d", &x, &y, &xf, &yf);
		e[i][0] = xf;
		e[i][1] = yf;
		s[x][0].push_back(i);
		s[y][1].push_back(i);
	}
	e[0][0] = e[0][1] = 0;
	e[n+1][0] = e[n+1][1] = max(xt, yt) + 50;
	s[xt][0].push_back(n+1);
	s[yt][1].push_back(n+1);
	int a, b;
	scanf("%d %d", &a, &b);
	if (find(b, n+1, 0) && find(a, b, 0) && find(0, a, 0)) {
		print(n);
		return 0;
	} else path.clear();
	if (find (b, n+1, 1) && find(a, b, 1) && find(0, a, 1)) {
		print(n);
		return 0;
	} else path.clear();
	if (find (a, n+1, 0) && find(b, a, 0) && find(0, b, 0)) {
		print(n);
		return 0;
	} else path.clear();
	//printf("%d\n", find(b, a, 1) && find(0, b, 1) && find(a, n+1, 1));
	if (find (a, n+1, 1) && find(b, a, 1) && find(0, b, 1)) {
		print(n);
		return 0;
	} else path.clear();
	printf("-1\n");
	return 0;
}


















