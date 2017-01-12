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

const int MAXN = 512345;

int n, m, k;
int s[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	ll sum = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		sum += (ll)s[a];
	}
	if(n == 1){
		puts("0");
		return 0;
	}
	sort(s, s+n);
	int i = 0, j = n-1;
	while(i < j){
		while(s[i+1] == s[i] && i < j)
			i++;
		while(s[j-1] == s[j] && i < j)
			j--;

	}

}
