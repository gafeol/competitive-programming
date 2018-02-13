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
int s[MAXN];

int x[3], y[3], r[3];

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<2;a++){
			scanf("%d%d%d", &x[a], &y[a], &r[a]);
		}
		if(r[1] > r[0]){
			swap(x[0], x[1]);
			swap(y[0], y[1]);
			swap(r[0], r[1]);
		}
		if(x[0] == x[1] && y[0] == y[1]){
			if(r[0] == r[1])
				puts("Oops, too many points");
			else
				puts("There are no points");
			continue;
		}
		int d = (x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]);
		if(d + r[1] < r[0]){
			puts("There are no points");
			continue;
		}
	
	}
}
