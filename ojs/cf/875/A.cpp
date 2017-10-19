
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

int sum(int x){
	int res = 0;
	while(x != 0){
		res += x%10;
		x /= 10;
	}
	return res;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<100 && n-a >= 0;a++){
		if(n-a + sum(n-a) == n)
			ans.pb(n-a);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int x: ans){
		printf("%d\n", x);
	}
}

