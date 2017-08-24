#include "bits/stdc++.h"
using namespace std;
using point = complex<long double>;

const int N = 200;
long double eps = 1e-5;

int n;
point p[N];
long double tot_area, a;

long double cross(point a, point b) { return .5*abs(imag(a*conj(b))); }
long double area(long double s){
	long double ans = tot_area;
	for(int i=0;i<n;i++){
		int j = (i+1)%n, k = (i+n-1)%n;
		ans -= cross((p[j]-p[i])/s, (p[k]-p[i])/s);
	}
	return ans;
}

int main(){
	scanf(" %Lf%d", &a, &n);
	for(int i=0;i<n;i++){
		long double x, y; scanf("%Lf%Lf", &x, &y);
		p[i] = {x,y};
	}

	for(int i=0;i<n;i++)
		tot_area += .5*imag(p[(i+1)%n]*conj(p[i]));
	tot_area = abs(tot_area);

	long double lo = 2, hi = 1e3;
	while(abs(hi-lo) > eps){
		long double mid = .5*(lo + hi);
		if(area(mid) <= a*tot_area - eps) lo = mid;
		else 						hi = mid;
	}
	printf("%.6Lf\n", .5*(lo + hi));
}
