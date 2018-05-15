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

const int MAXN = 312;

int n, k;

int m[6][MAXN][MAXN];
int M[MAXN][MAXN];
int v[] = {0, 1, 2, 3};

int main (){
	scanf("%d", &n);
	int vi[] = {0, 0, n, n};
	int vj[] = {0, n, 0, n};
	for(int k=0;k<4;k++){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				char c;
				scanf(" %c", &c);
				m[k][a][b] = (c-'0');
			}
		}
	}
	int res = INT_MAX;
	do{
		for(int kk=0;kk<4;kk++){
			int k = v[kk];
			for(int a=0;a<n;a++){
				for(int b=0;b<n;b++){
					M[vi[kk] + a][vj[kk] + b] = m[k][a][b];	
				}
			}
		}
		int t = 0;
		int ans = 0;
		for(int a=0;a<2*n;a++){
			for(int b=0;b<2*n;b++){
				ans += (M[a][b] != t);			
				t = 1 - t;
			}
			t = 1 - t;
		}
		res = min(res, ans);
		t = 1;
		ans = 0;
		for(int a=0;a<2*n;a++){
			for(int b=0;b<2*n;b++){
				ans += (M[a][b] != t);			
				t = 1 - t;
			}
			t = 1 - t;
		}
		res = min(res, ans);
	} while(next_permutation(v, v+4));
	printf("%d\n", res);
}
