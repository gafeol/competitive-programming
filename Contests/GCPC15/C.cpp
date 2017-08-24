#include "bits/stdc++.h"
using namespace std;
using point = complex<double>;

const int N = 200;
double eps = 1e-8;

int n;
point p[N];
double tot_area, ear, a;

double cross(point a, point b) { return .5*imag(a*conj(b)); }

int main(){
	scanf(" %lf%d", &a, &n);
	for(int i=0;i<n;i++){
		double x, y; scanf("%lf%lf", &x, &y);
		p[i] = {x,y};
	}

	for(int i=0;i<n;i++)
		tot_area += cross(p[(i+1)%n] , p[i]);
	tot_area = abs(tot_area);
	
	for(int i=0;i<n;i++)
		ear += cross(p[(i+n-1)%n] - p[i], p[(i+1)%n] - p[i]);
	ear = abs(ear);
	
	double s = sqrt(ear / (tot_area*(1.-a)));
	
	printf("%.6lf\n", s);
}
