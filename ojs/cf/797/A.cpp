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

vector<int> res;

int main (){
	scanf("%d%d", &n, &k);
	for(int a=2;k > 0 && a<=n;a++){
		while(k > 0 && n%a == 0){
			res.pb(a);
			k--;
			n /= a;
		}
	}
	if(!k){
		for(int i=0;i<res.size()-1;i++){
			printf("%d ", res[i]);
		}
		printf("%d\n", res[res.size()-1]*n);
	}
	else
		puts("-1");
}
