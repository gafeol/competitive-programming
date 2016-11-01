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

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	if(n == 1){
		printf("0\n");
		for(int a=0;a<n;a++){
			printf("%d ", s[a]);
		}
		return 0;
	}
	int res = 0;
	for(int a=1;a<n;a++){
		if(s[a] + s[a-1] < m){
			res += (m - s[a] - s[a-1]);
			s[a] += m - s[a] - s[a-1];
		}
	}
	printf("%d\n", res);
	for(int a=0;a<n;a++){
		printf("%d ", s[a]);
	}
}
