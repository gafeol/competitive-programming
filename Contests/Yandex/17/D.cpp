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
int s[MAXN], op[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		s[a] = !(s[a]&1);
		debug("%d ", s[a]);
	}
	puts("\n");
	int res = 0;
	for(int a=0;a<n;a++){
		if(op[a] > 1) continue;

		if((s[a]^op[a])&1){
			debug("inverte em %d\n", a);
			res++;
			op[a] ^= 1;
			op[a+1] ^= 1;
			if(a == 0 || op[a-1] > 1)
				op[a+2] = 2;
			else{
				op[a+2] = 1;
				if(a + 1 >= n){
					res = INT_MIN;
					break;
				}
			}
		}
	}
	res = max(-1, res);
	printf("%d\n", res);
	
	for(int a=0;a<n;a++){
		debug("%d ", op[a]);
		s[a] = s[a]^1;
		op[a] = 0;
	}
	debug("\n");
	res = 0;
	for(int a=0;a<n;a++){
		if(op[a] > 1) continue;

		if((s[a]^op[a])&1){
			res++;
			op[a] ^= 1;
			op[a+1] ^= 1;
			if(a == 0 || op[a-1] > 1)
				op[a+2] = 2;
			else{
				op[a+2] = 1;
				if(a + 1 >= n){
					res = INT_MIN;
					break;
				}
			}
		}
	}
	res = max(-1, res);
	printf("%d\n", res);

}
