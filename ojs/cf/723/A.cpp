

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

int test(int x){
	int ans = 0;
	for(int a=0;a<n;a++){
		ans += abs(s[a] - x);

	}
	return ans;
}

int main (){
	n = 3;
	int sum = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		sum += s[a];
	}
	int res =0;
	res = min(test(s[0]), min(test(s[1]), min(test(s[2]), min(test(sum/3), min(test(sum/3 - 1), test(sum/3 + 1))))));
	printf("%d\n", res);
}
