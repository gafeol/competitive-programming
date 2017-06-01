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
	for_tests(t, tt){
		int res = 1;
		scanf("%d", &n);
		int mx = 1;
		int r = sqrt(n) + 1;
		for(int a=2;a<=r && a<= n;a++){
			int cnt =0;
			while(n%a == 0){
				n /= a;
				cnt++;
			}
			mx = max(mx, cnt);
		}
		printf("%d\n", mx);
	}
}
