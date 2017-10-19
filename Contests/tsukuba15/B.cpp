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

const int N = 1000;

int n;
double x[N];
int r[N];

int main (){
	while (scanf (" %d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf (" %d", r + i);
		for (int i = 0; i < n; i++){
			x[i] = r[i];
			for (int j = 0; j < i; j++)
				x[i] = max (x[i], x[j] + 2 * sqrt (r[i] * r[j]));
		}
		double ans = x[0] + r[0];
		for (int i = 1; i < n; i++)
			ans = max (ans, x[i] + r[i]);
		printf ("%.20f\n", ans);
	}
}

