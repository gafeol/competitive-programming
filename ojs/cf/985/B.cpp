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

const int MAXN = 2123;

int n, m, k;
int s[MAXN][MAXN];
int sum[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			char c;
			scanf(" %c", &c);
			s[a][b] = (c == '1');
			sum[b] += s[a][b];
		}
	}
	for(int a=0;a<n;a++){
		int ok = 1;
		for(int b=0;b<m;b++){
			sum[b] -= s[a][b];
			if(sum[b] == 0) ok = 0;
		}
		for(int b=0;b<m;b++)
			sum[b] += s[a][b];
		if(ok){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	
}

