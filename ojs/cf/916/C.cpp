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
const int INF = 1e9;

int n, m, k;
int s[MAXN];

int main (){
	int sum = 100003;
	scanf("%d%d", &n, &m);
	printf("%d %d\n", sum, sum);
	for(int a=1;a<n-1;a++){
		printf("%d %d 1\n", a, a+1); 
		sum--;
		m--;
	}
	printf("%d %d %d\n", n-1, n, sum); 
	m--;
	for(int a=1;a<=n;a++){
		if(m == 0) break;
		for(int b=a+2;b<=n;b++){
			if(m == 0) break;
			m--;
			printf("%d %d %d\n", a, b, INF);
		}
	}
}

