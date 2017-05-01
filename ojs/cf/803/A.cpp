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

const int MAXN = 212;

int n, m, k;
int s[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &k);
	if(k > n*n){
		puts("-1");
		return 0;
	}
	for(int a=0;a<n;a++){
		for(int b=a;b<n;b++){
			if(a == b){
				if(k > 0){
					s[a][b] = 1;
					k--;
				}
			}
			else{
				if(k > 1){
					s[a][b] = 1;
					s[b][a] = 1;
					k-=2;
				}
			}
		}
	}
	if(k == 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				printf("%d ", s[a][b]);
			}
			printf("\n");
		}
	}
	else
		puts("-1");
}
