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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN][3];

bool go(ll w){
	for(int t=0;t<2;t++){
		int ult = -1;
		for(int a=0;a<n;a++){
			if(s[a][t] <= w) continue;
			if(ult == -1)
				ult = s[a][t];
			else{
				if(ult == s[a][t])
					ult = -1;
				else
					return 0;
			}
		}
		if(ult != -1)
			return 0;
	}
	return 1;

}

int main (){
	scanf("%d", &n);
	for(int t=0;t<2;t++){
		for(int a=0;a<n;a++){
			scanf("%d", &s[a][t]);
		}
	}
	ll i = 0, j = 1000000001;
	while(i < j){
		ll m = (i + j)/2;
		if(go(m))
			j = m;
		else
			i = m + 1;
	}
	printf("%lld\n", i);
}

