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

int n;
double l, bs, ps, k;

pii s[MAXN];

double t[MAXN], v[MAXN];

double dist(int a, double t){
	double x = s[a].fst;
	x -= bs*t;
	return x;
}

double temp(int a, double t){
	return dist(a, t)/bs;
}

double vel(int a, double t, double y){
	if(temp(a, t) == 0)
		return 1e10;
//	printf("%lf / %lf \n", (s[a].snd - y), temp(a, t));
	return (s[a].snd - y)/temp(a, t);
}

int main (){
	scanf("%d%lf%lf%lf", &n, &l, &bs, &ps);
	double mx = -1;
	int imx = 0, imn = 0;
	for(int a=0;a<n;a++){
		int x, y;
		scanf("%d %d", &x, &y);
		s[a] = pii(x, y);
		if(y > s[imx].snd)
			imx = a;
		if(y < s[imn].snd)
			imn = a;
		t[a] = (double)x/bs;
	//	printf("time %.2f\n", t[a]);
		if(t[a] != 0)
			v[a] = (double)y/t[a];
		else
			v[a] = DBL_MAX;
	//	printf("he must %.5lf\n", v[a]);
		mx = max(mx, v[a]);
	}
	if((double)ps >= mx){
		printf("%.10lf\n", (double)l/ps);
		return 0;
	}
	double y = 0, t  = 0;
	for(int a=imn;a != imx;a = (a+1)%n){
		double vm = vel(a, t, y);
	//	printf("vm %.2f\n", vm);
		if(s[a].snd - y == 0){
			t += temp(a, t);
			continue;
		}
		t += (s[a].snd - y)/min(vm, (double)ps);
		y = s[a].snd;
//		printf("chego em %.2lf com %.2lf\n", y, t);
	}
	t += (l - y)/ps;
	y = l;
//	printf("chego em %.2lf com %.2lf\n", y, t);
	printf("%.10lf\n", t);
}
