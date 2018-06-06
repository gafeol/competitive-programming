#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
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

const int MAXX = 1010;

int n[2], m, k;

multiset<pdi> q[2][MAXX];

pii s[2][MAXN];

vector<pdi> p[MAXX];

pdi att[MAXN*2]; //dx, fimy

inline int add(pii a, pii b){
	double dx = (b.x - a.x)/((double)b.y - b.x);
	att[deg] = pdi(dx, b.y);
	deg++;
	return deg-1;
}

inline void check(int t, int a, int b){
	if(s[t][a].y > s[t][b].y) return ;
	if(s[t][a].y == s[t][b].y && s[t][a].x > s[t][b]) return ;
	p[s[t][a].y] = pdi(s[t][a].x, add(s[t][a], s[t][b]));
}

int main (){
	for_tests(t, tt){
		for(int ti=0;ti<2;ti++){
			scanf("%d", &n[ti]);
			for(int a=0;a<n[ti];a++){
				int x, y;
				scanf("%d %d", &x, &y);
				x += 500;
				y += 500;
				s[ti] = pii(x, y);
			}
		}
		for(int ti=0;ti<2;ti++){
			for(int a=0;a<n[ti];a++){
				//esq 
				int aa = (a+n[ti]-1)%n[ti];
				check(ti, a, aa);
				//dir
				aa = (a+1)%n[ti];
				check(ti, a, aa);
			}
		}
	}
}

