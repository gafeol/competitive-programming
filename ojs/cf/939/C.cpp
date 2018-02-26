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
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=n;a<2*n;a++)
		s[a] = s[a-n];
	int l, r;
	scanf("%d%d", &l, &r);
	int tam = r - l;
	int imx, mx = INT_MIN;
	int sum = 0;
	for(int a=0;a<tam;a++)
		sum += s[a];
	int ans;
	for(int a=0;a<n;a++){
		debug("a %d sum %d\n", a, sum);
		if(sum >= mx){
			if(sum == mx){
				int ans2 = (l - a + n)%n;
				if(ans2 == 0) ans2 = n;
				if(ans > ans2)
					ans = ans2;
			}
			else{
				mx = sum;
				imx = a;
				ans = (l - imx + n)%n;
				if(ans == 0) ans = n;
			}
		}
		sum -= s[a];
		sum += s[a+tam];
	}
	printf("%d\n", ans);
}

