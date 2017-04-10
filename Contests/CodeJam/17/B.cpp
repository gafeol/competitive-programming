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

ll n;
int dp[21][2][11];

vector <int> res;

ll dig(int i){
	ll nn = n;
	while(i--){
		nn /= 10ll;
	}
	return nn%10;
}

int go(int i, int lo, int ult){
	if(i == -1)
		return 1;
	
	int &r = dp[i][lo][ult];
	
	if(r != -1)
		return r;

	r = 0;
	if(lo){
		for(int d = 9;d >= ult;d--){
			r = max(r, go(i-1, lo, d));
			if(r == 1){
				res.pb(d);
				return r;
			}
		}
	}
	else{
		for(int d = dig(i);d >= ult;d--){
			r = max(r, go(i-1, (d != dig(i)), d)); 
			if(r == 1){
				res.pb(d);
				return r;
			}
		}
	}
	return r;
}

int main (){
	for_tests(t, tt){
		memset(dp, -1, sizeof(dp));
		scanf("%lld", &n);
		go(19, 0, 0); 				
		printf("Case #%d: ", tt);
		int mx = 0;
		for(int i = res.size()-1;i >= 0;i--){
			mx = max(mx, res[i]);
			if(mx == 0) continue;
			printf("%d", res[i]);
		}
		if(mx == 0) printf("0");
		printf("\n");

		res.clear();
	}
}
