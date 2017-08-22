
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

const int MAXN = 212345, INF = 0x3f3f3f3f;

int n, m, k;
int s[MAXN];

stack<int> sp, ov;

int main (){
	scanf("%d", &n);
	sp.push(INF);
	ov.push(1);
	int res = 0;
	int v, mx;
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d",  &v);
		}
		else if(t == 2){
			while(ov.top() == 0){
				ov.pop();
				res++;
			}
		}
		else if(t == 3){
			scanf("%d", &mx);
			sp.push(mx);
		}
		else if(t == 4){
			ov.push(1);
		}
		else if(t == 5){
			sp.push(INF);
		}
		else{
			ov.push(0);
		}

		while(v > sp.top()){
			sp.pop();
			res++;
		}
	}
	printf("%d\n", res);
}

