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

int main (){
	int i, l, r;
	scanf("%d%d%d%d", &n, &i, &l, &r);
	int res = INT_MAX;
	int ini = i;
	int ans = 0;
	if(l != 1){
		ans += abs(i - l) + 1;
		i = l;
	}
	if(r != n){
		ans += abs(r - i) + 1;
	}

	res = min(res, ans);

	ans = 0;
	i = ini;
	if(r != n){
		ans += abs(r - i) + 1;
		i = r;
	}
	if(l != 1){
		ans += abs(i - l) + 1;
	}
	res = min(res, ans);
	printf("%d\n", res);

}

