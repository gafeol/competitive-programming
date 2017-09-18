#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;

#define double long double

typedef pair <double, double> pii;
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

const double EPS = 1e-8;

int n, m, k;
pii s[MAXN];

double r;

double d(pii a, pii b){
	return sqrt((a.fst - b.fst)*(a.fst - b.fst) + (a.snd - b.snd)*(a.snd - b.snd));
}

double area(double a, double b, double c){
	double p = (a+b+c)/2.;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main (){
	clock_t clk = clock();
	scanf("%Lf %d", &r, &n);
	double A = 0;
	for(int a=0;a<n;a++){
		scanf("%Lf %Lf", &s[a].fst, &s[a].snd);
	}
	for(int a=1;a<n-1;a++){
		A += area(d(s[0], s[a]), d(s[0], s[a+1]), d(s[a], s[a+1]));
	}
	double m = 2;
	double ar = A;
	for(int a=0;a<n;a++){
		pii nxt = pii((s[a].fst + s[(a+1)%n].fst)/m, (s[a].snd + s[(a+1)%n].snd)/m);
		pii bef = pii((s[a].fst + s[(a+n-1)%n].fst)/m, (s[a].snd + s[(a+n-1)%n].snd)/m);
		ar -= area(d(s[a], nxt), d(s[a], bef), d(nxt, bef)); 
	}
	printf("%.10Lf\n", 2.*sqrt((A - ar)/(A*(1-r))));
}
