#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define double long double
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
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

const int MAXN = 4123;
const double PI = acos(-1);
const double DEL = 1e-10;

int n, m, k;

vector<pdi> v;

struct ptd{
	double x, y;

	ptd(){}
	ptd(double xx, double yy){
		x = xx;
		y = yy;
	}

	ptd operator-(ptd o){
		return ptd(x - o.x, y - o.y);
	}
} s[MAXN];

double dist(int i, int j){
	return (s[i].x - s[j].x)*(s[i].x - s[j].x) + (s[i].y - s[j].y)*(s[i].y - s[j].y);
}

void add(int i, int j, double r){
	if(dist(i, j) > ((double)4)*r*r)
		return ;
	
	double d = sqrt(dist(i, j));
	double a = d/((double)2.);
	double h = sqrt(r*r - a*a);

	ptd m, p, pp;
	m.x = (s[i].x + s[j].x)/((double)2.);
	m.y = (s[i].y + s[j].y)/((double)2.);

	p.x = m.x + h*(s[j].y - s[i].y)/d;
	p.y = m.y - h*(s[j].x - s[i].x)/d;

	pp.x = m.x - h*(s[j].y - s[i].y)/d;
	pp.y = m.y + h*(s[j].x - s[i].x)/d;

	double t1, t2;
	ptd v1, v2;
	ptd ss;
	ss.x = (double)s[i].x;
	ss.y = (double)s[i].y;


	v1 = p - ss;
	v2 = pp - ss;
//	debug("v1.x %.3f %3.f\n", v1.x, v1.y);

	t1 = atan2(v1.y, v1.x);
	t2 = atan2(v2.y, v2.x);
	
//	debug("t1 %.5f t2 %.5f\n", t1, t2);
	if(t2 < t1){
		v.pb(pdi(t1, 0));
		v.pb(pdi(0, 0));
		v.pb(pdi(((double)2)*PI + DEL, 1));
		v.pb(pdi(t2 + DEL, 1));
	}
	else{
		v.pb(pdi(t1, 0));
		v.pb(pdi(t2 + DEL, 1));
	}
}

int main (){
	clock_t clk = clock();
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%Lf %Lf", &s[a].x, &s[a].y);
	}
	double ri = 0., rj = 10000000.;
	while(((double)clock() - clk)/CLOCKS_PER_SEC < 1.7){
		double rm = (ri + rj)/2.;
//		debug("test %.5f %.5f %.5f\n", ri, rj, rm);
		int ans = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i == j) continue;
				add(i, j, rm);
			}
			sort(v.begin(), v.end());
			int cnt = 1;
			for(pdi ev: v){
	//			debug("ev %.5f %d\n", ev.fst, ev.snd); 
				if(ev.snd == 0)
					cnt++;
				else
					cnt--;
				ans = max(ans, cnt);
			}
			v.clear();
		}
		if(ans >= m)
			rj = rm;
		else
			ri = rm;
	}
	printf("%.10Lf\n", ri);
}
