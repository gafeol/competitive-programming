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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 21234;

int n, m, k;
int nxt[MAXN];
char s[MAXN], v[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &k);
		for(int a=0;a<n;a++){
			scanf(" %c", &v[a]);
		}
		int mx = 0;
		v[n] = ' ';
		nxt[n-1] = n-1;
		for(int a=n-2;a>=0;a--){
			if(v[a] != v[a+1])
				nxt[a] = a;
			else
				nxt[a] = nxt[a+1];
			mx = max(mx, nxt[a]-a+1);
		}
		if(mx < k){
			puts("-1");
			continue;
		}
		int res = 0;
		int a = 0;
		while(a<n){
			res += (int)ceil(((double)(nxt[a] - a +1))/((double)k));	
			a = nxt[a] + 1;
		}
		printf("%d\n", res);
	}
}
