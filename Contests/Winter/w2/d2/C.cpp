#include <bits/stdc++.h>
#define ff first
#define ss second
#define double long double
using namespace std;

inline int cmp(double x, double y = 0, double tol = 1e-9) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator +(point q) { return point(x + q.x, y + q.y); }
  point operator -(point q) { return point(x - q.x, y - q.y); }
  point operator /(double t) { return point(x / t, y / t); }
  point operator *(double t) { return point(x * t, y * t); }
  double mod() { return sqrt(x*x + y*y); }
  point rotate(double t) { return point(x*cos(t) - y*sin(t), x*sin(t) + y*cos(t)); }
};

struct circle {
  point c; double r;
  circle(point c = point(0, 0), double r = 0.0) : c(c), r(r) {}
  bool inside(point &e) { return cmp((e - c).mod(), r) <= 0; }
};

pair<point, point> inter(circle a, circle b) {
  if (cmp(a.r, b.r) < 0) swap(a, b);
  double R = a.r, r = b.r, d = (b.c - a.c).mod();
  double x1 = (R*R - r*r + d*d) / (2*d);
  double h = 0.;
  if (cmp(R*R - x1*x1) > 0) h = sqrt(R*R - x1*x1);
  point v = ((b.c - a.c) / d) * R;
  return make_pair(a.c + v.rotate(atan2(h/R, x1/R)), a.c + v.rotate(atan2(-h/R, x1/R)));
}

const int MAXN = 51;

circle v[MAXN];
double vel[MAXN];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i].c.x >> v[i].c.y >> vel[i];
    }
    double lo = 0, hi = 1e7;
    for (int iter = 0; iter < 200; iter++) {
      double mid = (hi + lo) / 2.;
      bool ok = false;
      for (int i = 0; i < n; i++) v[i].r = vel[i] * mid;
      bool ok2;
      for (int i = 0; i < n; i++) {
        ok2 = true;
        for (int j = 0; j < n; j++) {
          if (!v[j].inside(v[i].c)) {
            ok2 = false;
            break;
          }
        }
        if (ok2) goto nxt;
      }
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (cmp(v[i].r + v[j].r, (v[i].c - v[j].c).mod()) < 0) {
            continue;
          }
          pair<point, point> pp = inter(v[i], v[j]);
          for (int potato = 0; potato < 2; potato++) {
            point pivot = pp.ff;
            for (int k = 0; k < n; k++) {
              if (!v[k].inside(pivot)) goto nxt2;
            }
            ok = true;
            goto nxt;
            nxt2:
            swap(pp.ff, pp.ss);
          }
        }
      }
      nxt:
      if (ok || ok2) hi = mid;
      else lo = mid;
    }
    printf("%.10Lf\n", lo);
  }
  return 0;
}
