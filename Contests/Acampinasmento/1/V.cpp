#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define pi 3.14159265358979311600
#define eps 1e-7

struct point {
	ld x, y;
	point (ld a, ld b) {
		x = a;
		y = b;
	}
	ld dim() {
		return sqrt(x*x+y*y);
	}
	void operator* (ld c) {
		x *= c;
		y *= c;
	}
	void operator/ (ld c) {
		x /= c;
		y /= c;
	}
	void rotate(ld ang) {
		ld tempx = cos(ang)*x - sin(ang)*y;
		ld tempy = sin(ang)*x + cos(ang)*y;
		x = tempx;
		y = tempy;
	}
	void print() {
		printf("%Lf %Lf\n", x, y);
	}
};

bool close(point a, point b) {
	point p3(a.x-b.x, a.y-b.y);
	ld k = p3.dim();
	if (k <= eps) return true;
	else return false;
}

bool isInside(point p, point c, ld r) {
	if ((p.x-c.x)*(p.x-c.x)+(p.y-c.y)*(p.y-c.y) <= r*r) return true;
	else return false;
}

int main () {
	int n;
	scanf("%d", &n);
	while (n--) {
		long long a, b, a1, b1, r, R;
		scanf("%lld %lld %lld", &a, &b, &R);
		point p1(a, b);
		scanf("%lld %lld %lld", &a1, &b1, &r);
		point p2(a1, b1);
		if (R < r) swap(p1, p2);
		point p3(p2.x-p1.x, p2.y-p1.y);
		point p4(p2.x-p1.x, p2.y-p1.y);
		if (a1 == a && b1 == b && r == R) {
			printf("Oops, too many points\n\n");
			continue;
		}
		long long dist = (a1-a)*(a1-a)+(b1-b)*(b1-b);
		if (dist > (r+R)*(r+R) || dist < (R-r)*(R-r)) {
			printf("There are no points\n\n");
			continue;
		}
		if (dist == (r+R)*(r+R)) {
			p3/(ld)(R+r);
			p3*(ld)R;
			printf("There are only 1 of them\n%.6Lf %.6Lf\n\n", p3.x, p3.y);
			continue;
		}
		p3/(ld)(sqrt(dist));
		p3*(ld)R;
		p4/(ld)(sqrt(dist));
		p4*(ld)R;
		ld ang = pi/2;
		p3.rotate(ang);
		p4.rotate(-ang+2*pi);
		for (int i=0;i<1000;i++) {
			ang /= 2;
			if (isInside(p3, p2, r)) { 
				p4.rotate(-ang+2*pi);
				p3.rotate(ang);
			}
			else {
				p4.rotate(ang);
				p3.rotate(2*pi-ang);
			}
		}
		if (max(p3.x-p4.x,p4.x-p3.x) <= eps) {
			if (p3.y > p4.y) swap(p3, p4);
		}
		else if (p3.x > p4.x) swap(p3, p4);
		printf("There are only 2 of them\n%.6Lf %.6Lf\n%.6Lf %.6Lf\n\n", p3.x, p3.y, p4.x, p4.y);
	}
}













