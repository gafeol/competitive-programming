
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

vector<int> ans;

int main (){
	scanf("%d", &n);
	for(int a=2;a<=n;a+=2)
		ans.pb(a);
	for(int a=1;a<=n;a+=2)
		ans.pb(a);
	for(int a=2;a<=n;a+=2)
		ans.pb(a);
	printf("%d\n", (int)ans.size());
	for(int u: ans){
		printf("%d ", u);
	}
	puts("");
}
