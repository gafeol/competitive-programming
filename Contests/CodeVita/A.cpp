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

const int MAXN = 21;

const double EPS = 1e-8;

int n;
double k;
double s[MAXN];
double pos[MAXN];

double readf(){
	double a, b;
	scanf("%lf", &a);
	char c = getchar();
	b = 1;
	if(c == '/')
		scanf("%lf", &b);
	return a/b;	
}


int main (){
	scanf("%d", &n);
	k = readf();
	for(int a=0;a<n;a++){
		s[a] = readf()/2.;
		pos[a] = k*a;
	}
	int res = INT_MAX;
	int resbm;
	for(int i=0;i<(1<<n);i++){
		double mx = 0;
		for(int a=0;a<n;a++){
			if(((1<<a)&i) == 0) continue;	
			if(pos[a] - s[a] - EPS <= mx){
				mx = pos[a] + s[a];
			}
		}
		if(mx+EPS >= pos[n-1]){
			int nb = __builtin_popcount(i);
			if(nb < res){
				res = nb;
				resbm = i;
			}
		}
	}

	if(res == INT_MAX)
		printf("INSUFFICIENT LAMPS");
	else{
		printf("%d\n", res);

		vector<int> ans[2];
		for(int a=0;a<n;a++){
			//printf("a %d t: %d\n", a, ((1<<a)&resbm));
			ans[(((1<<a)&resbm) > 0)].pb(a+1);
		}
		for(int i=0;i<(int)ans[1].size();i++){
			printf("%d ", ans[1][i]);
		}
		printf("\n");
		for(int i=0;i<(int)ans[0].size();i++){
			printf("%d", ans[0][i]);
			if(i < (int)ans[0].size()-1 || i == 0)
				printf(" ");
		}
	}
}

