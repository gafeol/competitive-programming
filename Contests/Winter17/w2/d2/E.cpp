#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
using namespace std;

typedef long long lint;

const int MAXN = 412, MAXK = 11, MOD = 1e9 + 7;

int vamo[1 << MAXK], vamo2[1 << MAXK];
lint dp[MAXN][1 << MAXK];
int n, k, kk;

bool pal(int s) {
  int bit[MAXK];
  for (int i = 0; i < k; i++) bit[i] = (s >> i) & 1;
  for (int i = 0; i < k; i++) if (bit[i] != bit[k - 1 - i]) return false;
  return true;
}

bool pal2(int s) {
  int bit[MAXK];
  for (int i = 0; i < kk; i++) bit[i] = (s >> i) & 1;
  for (int i = 0; i < kk; i++) if (bit[i] != bit[kk - 1 - i]) return false;
  return true;
}

lint f(int idx, int s) {
  debug("%d %d\n", idx, s);
  if (idx >= k && vamo[s]) return 0;
  if (idx >= kk && vamo2[s]) return 0;
  if (idx == n) return 1;
  lint &ret = dp[idx][s];
  if (ret == -1) {
    int aux = (s << 1);
    aux %= (1 << kk);
    ret = (f(idx + 1, aux + 1) + f(idx + 1, aux)) % MOD;
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    kk = k + 1;
    for (int i = 0; i < (1 << kk); i++) vamo[i] = pal(i);
    for (int i = 0; i < (1 << kk); i++) vamo2[i] = pal2(i);
    if (n < k) {
      cout << (1 << n) << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << kk); j++) {
        dp[i][j] = -1;
      }
    }
    cout << f(0, 0) << endl;
  }
  return 0;
}
