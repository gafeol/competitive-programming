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
int s[MAXN]; 
char M[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf(" %c", &M[a][b]);
			}
		}
		char c[] = {'R', 'G'};
		int ans = 0, res = 0;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				char l = c[((a+b)&1)];
				if(M[a][b] == c[((a+b)&1)]) continue; 
				if(l == 'G') ans += 5;
				else ans += 3;
			}
		}
		res = ans;
		swap(c[0], c[1]);	
		ans = 0;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				char l = c[((a+b)&1)];
				if(M[a][b] == c[((a+b)&1)]) continue; 
				if(l == 'G') ans += 5;
				else ans += 3;
			}
		}
		res = min(res, ans);
		printf("%d\n", res);
	}	
}

