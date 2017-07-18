#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
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

const int MAXN = 212345;

const double EPS = 1e-8;

int n, m, k;
double s[MAXN];
pdi q[MAXN];

int res[MAXN];
int ans[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lf", &s[a]);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		scanf("%lf", &q[a].fst);
		q[a].snd = a;
	}
	sort(q, q+m);
	for(int a=0;a<n;a++){
		double l = 0.9*((double)s[a]);
		double r = 1.1*((double)s[a]);
		int j = upper_bound(q, q+m, pdi(r+EPS, 10000000)) - q;
		int i = lower_bound(q, q+m, pdi(l-EPS, 0)) - q;
		res[i]++;
		res[j]--;
	}
	int acu = 0;
	for(int a=0;a<m;a++){
		acu += res[a];
		ans[q[a].snd] = acu;
	}
	for(int a=0;a<m;a++){
		printf("%d\n", ans[a]);
	}
}
