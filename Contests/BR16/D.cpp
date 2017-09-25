
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
int ne[MAXN];

int main (){
	long long resp = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n);
	int i = 1, j = n-1;
	int p = n-1;
	ne[0] = s[p--];
	while(p >= 0) {
		ne[i++] = s[p--];
		if(p >= 0) ne[j--] = s[p--];
	}
	for (int i=0;i<n;i++) {
		resp += ((long long)ne[i])*((long long)ne[(i+1)%n]);
	}
	double pi = acos(-1);
	printf("%.3lf\n", ((double)resp/2.0)*sin((2.0*pi)/((double)n)));
}

