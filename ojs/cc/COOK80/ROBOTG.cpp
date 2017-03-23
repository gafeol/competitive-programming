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

int mv[300];
int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};
int res[300];
char s[MAXN];

int main (){
	mv['R'] = 0;
	mv['L'] = 1;
	mv['U'] = 2;
	mv['D'] = 3;
	for_tests(t, tt){
		memset(res, 0, sizeof(res));
		scanf("%d%d", &n, &m);
		int i, j;
		i = j =0;
		scanf(" %s", s);
		int tam = strlen(s);
		for(int a=0;a<tam;a++){
			i += vi[mv[s[a]]];	
			j += vj[mv[s[a]]];
			if(mv[s[a]] < 2){
				res[0] = max(res[0], j);
				res[1] = min(res[1], j);
			}
			else{
				res[2] = min(res[2], i);
				res[3] = max(res[3], i);
			}
		}
		for(int a=0;a<4;a++){
			debug("res[%d]: %d\n", a, res[a]);
		}
		if(res[0] - res[1] + 1 > m || -res[2] + res[3] + 1 > n){
			puts("unsafe");
			continue;
		}
		puts("safe");
	}
}
