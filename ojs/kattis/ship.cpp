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
#define it itersda

const int MAXN = 212345;

int n, m, k;
double w, sship, sme, ini, fim;

map<double, int> ind;

int main (){
		scanf("%d %lf %lf %lf %lf %lf", &n, &w, &sship, &sme, &ini, &fim);
	for(int a=0;a<n;a++){
		char d;
		int t;
		scanf(" %c %d", &d, &t);
		while(t--){
			double p, l;
			scanf("%lf %lf", &l, &p);
			if(d == 'E')
				p = -p;
			p -= ((a*w)/sme)*sship;
			ind[p]++;
			ind[p+l]--;
		}
	}
	int cnt = 0;
	double bef = ini;
	double res = 0;
	for(auto &it: ind){
		double i = it.fst;
		int bal = it.snd;
		if(cnt == 0){
			res = max(res, min((double)fim, i/sship - (double)w/sme) - 	max((double)ini, bef));
			debug("na pos %.3f\n novo res %.5f\n", i, min((double)fim, i/sship - (double)w/sme) - 	max((double)ini, bef));
		}
		cnt += bal;
		bef = i/sship;
	}
	res = max(res, (double)fim - max((double)ini, bef));
	printf("%.10f\n", res);
}
