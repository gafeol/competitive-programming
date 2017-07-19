#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1123123;

int v[MAXN];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) v[i] = n - i;
    while (m--) {
      int a, b;
      cin >> a >> b;
      v[a]--; v[b]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (!v[i]) { ans = i; break; }
    if (ans) printf("2 %d\n", ans);
    else printf("1\n");
  }
  return 0;
}
