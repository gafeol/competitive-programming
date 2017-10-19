
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
int ap[MAXN];

int main (){
	while(scanf("%d", &n) != EOF) {
		for (int i=0;i<=10000;i++) ap[i] = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for (int k=0;k<n;k++) {
		int v = 0;
		for (int i=0;i+k<n && i < 4;i++) {
			v *= 10;
			v += s[i+k];
			ap[v] = 1;
		}
	}
	for (int i=0;i<=10000;i++) {
		if (ap[i] == 0) {
			printf("%d\n", i);
			break;
		}
	}
	}
}

