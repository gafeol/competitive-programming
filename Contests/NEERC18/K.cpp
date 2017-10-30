
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
int s[MAXN], g[MAXN];
int l[MAXN], r[MAXN];
int lef = 0, righ = 0;

void inter(int a, int b) {
	lef = max(lef-1, a);
	righ = min(righ+1, b);
	if (lef > righ) {
		printf("-1\n");
		exit(0);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a], &g[a]);
	}
	l[0] = lef = s[0];
	r[0] = righ = s[0] + g[0];
	for (int i=1;i<n;i++) {
		inter(s[i], s[i]+g[i]);
		l[i] = lef;
		r[i] = righ;
	}
	vector<int> v;
	int st = r[n-1];
	long long sum = st - s[n-1];
	v.push_back(st);
	for (int i=n-2;i>=0;i--) {
		st = min(st+1, r[i]);
		sum += (long long)(st - s[i]);
		v.push_back(st);
	}
	printf("%lld\n", sum);
	for (int i=n-1;i>=0;i--) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

