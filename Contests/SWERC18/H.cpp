#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
struct edge {
	int v, c;
	bool operator< (const edge &o) const {
		return c > o.c;
	}
};
vector<edge> adj[N];

struct info {
	int a, b, c;
	bool operator< (const info &o) const {
		return make_pair(a, make_pair(b, c)) < make_pair(o.a, make_pair(o.b, o.c));
	}
};

int dist[N][4];

void dij(int st) {
	priority_queue<edge> pq;
	pq.push({st, 0});
	dist[st][st] = 0;
	while (pq.size()) {
		edge e = pq.top();
		pq.pop();
		if (e.c > dist[e.v][st])
			continue;
		for (auto ee: adj[e.v]) {
			if (dist[ee.v][st] > ee.c + e.c) {
				dist[ee.v][st] = ee.c + e.c;
				pq.push({ee.v, dist[ee.v][st]});
			}
		}
	}
}

int t[N << 3];

int query(int l, int r, int n) {
	int resp = 4 * N;
	//printf("query(%d, %d, %d) = ", l, r, n);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) resp = min(resp, t[l++]);
		if (r & 1) resp = min(resp, t[--r]);
	}
	//printf("%d\n", resp);
	return resp;
}

void modify(int pos, int val, int n) {
	//printf("modify(%d, %d, %d)\n", pos, val, n);
	for (t[pos += n] = val; pos != 1; pos >>= 1) {
		t[pos >> 1] = min(t[pos], t[pos^1]);
	}
}

int main() {
	int n, e; scanf("%d %d", &n, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	memset(dist, 0x5f, N * 4);
	for (int i = 0; i < 3; i++)
		dij(i);
	vector<info> v;
	set<int> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			s.insert(dist[i][j]);
		}
	}
	map<int, int> m;
	int p = 1;
	for (auto vl: s) {
		m[vl] = p++;
	}
	for (int i = 0; i < n; i++) {
		info f = {m[dist[i][0]], m[dist[i][1]], m[dist[i][2]]};
		v.push_back(f);
	}
	for (int i = 0; i < p; i++) {
		modify(i, 4 * N, p);
	}
	sort(v.begin(), v.end());
	int useful = (int)v.size();
	set<info> used;
	for (auto f: v) {
		//printf("a, b, c = %d %d %d\n", f.a, f.b, f.c);
		bool can_use = true;
		if (query(0, f.b, p) <= f.c) can_use = false;
		else if (query(f.b, f.b+1, p) < f.c) can_use = false;
		else if (query(f.b, f.b+1, p) == f.c) {
			if (used.find(f) == used.end()) {
				can_use = false;
			}
		}
		if (!can_use) useful--;
		else used.insert(f);
		modify(f.b, min(f.c, query(f.b, f.b, p)), p);
	}
	printf("%d\n", useful);
}
