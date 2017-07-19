#include <bits/stdc++.h>

using namespace std;

const int MAXN = 112;

// BEGIN FLOW

const int MAXV = 3*MAXN, INF = 0x7FFFFFFF;

struct edge {
  int dest, rev, cap, f;
  edge(int dest, int rev, int cap) : dest(dest), rev(rev), cap(cap) {
    f = 0;
  }
};

int dist[MAXV], ptr[MAXV];
vector<edge> adj[MAXV];
int V, S, T;

void add_edge(int a, int b, int cap = 1) {
  adj[a].push_back(edge(b, adj[b].size(), cap));
  adj[b].push_back(edge(a, adj[a].size() - 1, 0));
}

bool bfs() {
  for (int i = 1; i <= V; i++)
    dist[i] = -1;
  dist[S] = 0;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < adj[v].size(); i++) {
      edge e = adj[v][i];
      if (dist[e.dest] == -1 && e.cap > e.f) {
        dist[e.dest] = dist[v] + 1;
        q.push(e.dest);
      }
    }
  }
  return dist[T] != -1;
}

int dfs(int v, int f) {
  if (v == T) return f;
  for (; ptr[v] < adj[v].size(); ++ptr[v]) {
    edge &e = adj[v][ptr[v]];
    if (dist[e.dest]== dist[v] + 1 && e.cap > e.f) {
      int df = dfs(e.dest, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        adj[e.dest][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int max_flow() {
  int flow = 0;
  while (bfs()) {
    for (int i = 1; i <= V; i++)
      ptr[i] = 0;
    while (true) {
      int df = dfs(S, INF);
      if (df == 0) break;
      flow += df;
    }
  }
  return flow;
}

void clear() {
  for (int i = 1; i <= V; i++)
    adj[i].clear();
}

// END FLOW

int cost[MAXN][MAXN];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, c;
    cin >> n >> m >> k >> c;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> cost[i][j];
      }
    }
    V = T = n + 2*m + 2;
    S = n + 2*m + 1;
    int lo = 0, hi = 1e9, ans = -1;
    while (lo <= hi) {
      clear();
      int mid = (lo + hi) / 2;
      for (int i = 1; i <= n; i++) add_edge(S, i);
      for (int i = 1; i <= m; i++) add_edge(i + n, T), add_edge(i + n + m, T);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (cost[i][j] <= mid) add_edge(i, j + n);
          if (cost[i][j] + c <= mid) add_edge(i, j + n + m);
        }
      }
      if (max_flow() >= k) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
