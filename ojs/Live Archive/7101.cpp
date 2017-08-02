#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
double l[4];

double pi = acos(-1);

bool check(double x){
	return (x + l[0] >= l[1] && x + l[0] >= l[2] &&
			x + l[1] >= l[0] && x + l[1] >= l[2] &&
			x + l[2] >= l[0] && x + l[2] >= l[1]);
}

inline double ang(double b, double c, double a){
	return acos((a*a - b*b - c*c)/(2.*b*c));
}

double sum(double x){
	return ang(l[0], l[1], x) +
			ang(l[1], l[2], x) +
			ang(l[0], l[2], x);
}


int main (){
	for(int a=0;a<3;a++)
		scanf("%lf", &l[a]);
	double mx = min(min(l[0] + l[1], l[1] + l[2]), l[0] + l[2]);
	double i = 0, j = mx; 
	int op = 400;
	while(op--){
		double m = (i + j)/2.;
		if(!check(m) || sum(m) < 2.*pi)
			i = m;
		else
			j = m;
	}
	double ans = (i + j)/2.;
	printf("%.20f\n", ans*ans*sqrt(3)/4.) 
}
