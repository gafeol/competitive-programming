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

const float EPS = 1e-8;

int n, m;
float s[MAXN];
float k;

int main (){
	scanf("%f %d", &k, &n);
	for(int a=0;a<n;a++){
		scanf(" %f", &s[a]);
	}
	sort(s, s+n);
	if(n == 1){
		printf("0\n");
		return 0;	
	}
	int res = INT_MAX;
	for(int div=0;div<=500;div++){
		float val = s[0]/(div+1.);
		float mn = val;
		float mx = val;
		int ans = div;
		int d = div;
		for(int j=1;j<n;j++){
			while(d <= 500 && (s[j]/(d+1))*k > mn)
				d++;
			ans += d;
			mn = min(mn, s[j]/(d+1));
			mx = max(mx, s[j]/(d+1));
			if(mn/mx <= k + EPS){
				ans = INT_MAX;
				break;
			}
		}
		res  = min(res, ans);
	}
	printf("%d\n", res);
}
