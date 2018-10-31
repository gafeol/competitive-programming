#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct point {
	long double x, y;
	point operator- (const point &p) const {
		return {x - p.x, y - p.y};
	}
	point operator+ (const point &p) const {
		return {x + p.x, y + p.y};
	}
	point operator/ (long double l) {
		return {x / l, y / l};
	}
	point operator* (long double l) {
		return {x * l, y * l};
	}
	long double operator* (const point &p) const {
		return x * p.x + y * p.y;
	}
	long double operator^ (const point &p) const {
		return x * p.y - p.x * y;
	}
	long double len() {
		return sqrt(x * x + y * y);
	}
	void print() {
		//printf("{%lf, %lf}\n", x, y);
	}
};

struct rect {
	point a, b, c, d;
};

const long double EPS = 1e-9;

struct line {
	long double a, b, c;
	line() {}
	line(point s, point e) : a(e.y - s.y), b(s.x - e.x), c(a * s.x + b * s.y) {}
	bool parallel(const line &o) const {
		return abs(a * o.b - o.a * b) <= EPS;
	}
	point inter(const line &o) const {
		long double d = a * o.b - o.a * b;
		point p;
		if (abs(d) <= EPS) return p;
		p.x = (o.b * c - b * o.c) / d;
		p.y = (a * o.c - o.a * c) / d;
		return p;
	}
};

struct side {
	point a, b;
};

long double cross(point a, point b, point c) {
	return (c - a) ^ (b - a);
}

bool between_seg(point a, point b, point c) {
	return abs(cross(a, b, c)) <= EPS  && ((b - c) * (a - c) <= 0.0);
}

int sign(long double x) {
	if (x > 0.0) return 1;
	if (x == 0.0) return 0;
	return -1;
}

bool inter_seg(point a, point b, point c, point d) {
	if (between_seg(a, b, c) || between_seg(a, b, d) || between_seg(c, d, a) || between_seg(c, d, b)) return true;
	if ((sign(cross(a, b, c)) * sign(cross(a, b, d)) == -1) && (sign(cross(c, d, a)) * sign(cross(c, d, b)) == -1)) return true;
	return false;
}

vector<rect> rr;
vector<point> p;
vector<side> ss;

int get_resp(point a, point b) {
	int resp = 0;
	for (int i=0;i<rr.size();i++) {
		if (inter_seg(a, b, rr[i].a, rr[i].b) || 
			inter_seg(a, b, rr[i].b, rr[i].c) ||
			inter_seg(a, b, rr[i].c, rr[i].d) ||
			inter_seg(a, b, rr[i].d, rr[i].a))
			resp++;
	}
	//printf("resp pro segento {%lf, %lf}, {%lf, %lf} eh %d\n", a.x, a.y, b.x, b.y, resp);
	//getchar();
	return resp;
}

int solve(point a, point b, long double l) {
	int resp = 0;
	//printf("------------- {%lf, %lf}, {%lf, %lf}\n", a.x, a.y, b.x, b.y);
	//if (a.x == 3.0) printf("VAI SE FUDER SEU ARROMBADOOOOOOOOOOOOOOOOOOO\n");
	for (int i=0;i<ss.size();i++) {
		if (line(a, b).parallel(line(ss[i].a, ss[i].b))) {
			point bg = ss[i].a;	
			point dir = (a - b);
			dir = dir / dir.len();
			//printf("{%lf, %lf}, {%lf, %lf} => {%lf, %lf}\n", ss[i].a.x, ss[i].a.y, ss[i].b.x, ss[i].b.y, bg.x, bg.y);
			//getchar();
			resp = max(resp, get_resp(bg, bg + dir * l));
			resp = max(resp, get_resp(bg, bg + dir * (-l)));
			bg = ss[i].b;	
			dir = (a - b);
			dir = dir / dir.len();
			//printf("{%lf, %lf}, {%lf, %lf} => {%lf, %lf}\n", ss[i].a.x, ss[i].a.y, ss[i].b.x, ss[i].b.y, bg.x, bg.y);
			//getchar();
			resp = max(resp, get_resp(bg, bg + dir * l));
			resp = max(resp, get_resp(bg, bg + dir * (-l)));
		} else {
			point bg = line(a, b).inter(line(ss[i].a, ss[i].b));
			// vai comecar em bg
			point dir = (a - b);
			dir = dir / dir.len();
			//printf("{%lf, %lf}, {%lf, %lf} => {%lf, %lf}\n", ss[i].a.x, ss[i].a.y, ss[i].b.x, ss[i].b.y, bg.x, bg.y);
			//getchar();
			resp = max(resp, get_resp(bg, bg + dir * l));
			resp = max(resp, get_resp(bg, bg + dir * (-l)));
		}
	}
	return resp;
}

int main () {
	int r; long double l; scanf("%d %Lf", &r, &l);
	for (int i=0;i<r;i++) {
		long double x, y, x2, y2; scanf("%Lf %Lf %Lf %Lf", &x, &y, &x2, &y2);
		point a = {x, y};
		point b = {x, y2};
		point c = {x2, y2};
		point d = {x2, y};
		rr.pb({a, b, c, d});
		p.pb(a);
		p.pb(b);
		p.pb(c);
		p.pb(d);
		ss.pb({a, b});
		ss.pb({b, c});
		ss.pb({c, d});
		ss.pb({d, a});
	}
	int resp = 0;
	for (int i=0;i<p.size();i++) {
		for (int j=i+1;j<p.size();j++) {
			resp = max(resp, solve(p[i], p[j], l));
		}
	}
	printf("%d\n", resp);
}

