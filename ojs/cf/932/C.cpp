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

const int MAXN = 2123456;

int n, m, k[2];
int s[MAXN];

int res[MAXN];

int main (){
	scanf("%d%d%d", &n, &k[0], &k[1]);
	int q[2];
	q[0] = 0;
	q[1] = 0;
	for(int i=0;i*k[1] <= n;i++){
		if((n-(i*k[1]))%k[0] == 0){
			q[0] = (n-(i*k[1]))/k[0];
			q[1] = i;
			break;
		}
	}
	if(q[0] + q[1] == 0){
		puts("-1");
		return 0;
	}
	int ult = 1;
	for(int t=0;t<2;t++){
		while(q[t]--){
			int beg = ult;
			for(int a=0;a<k[t]-1;a++){
				res[ult] = ult+1;	
				ult++;
			}
			res[ult] = beg;
			ult++;
		}
	}
	for(int a=1;a<=n;a++)
		printf("%d ", res[a]);
	puts("");
}

