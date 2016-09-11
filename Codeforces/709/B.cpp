#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, s[112345], b;



int main (){
	scanf("%d%d", &n, &b);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	if(n == 1){
		printf("0\n");
		return 0;
	}
	sort(s, s+n);
	int res = 0;
	res = INT_MAX;
	res = min(res, min(abs(b - s[0]), abs(s[n-2] - b)) + s[n-2] - s[0]);
	res = min(res, min(abs(b - s[1]), abs(s[n-1] - b)) + s[n-1] - s[1]);
	printf("%d\n", res);
}
