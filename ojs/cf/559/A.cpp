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

#define count asdasfa

int count(int i, int j, int k){
	int ans = 0;
	int cnt = 2*j+1;
	for(int a=0;a<i;a++){
		ans += cnt;
		cnt+=2;
	}
	return ans;
}

int main (){
	n = 6;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}

	int res = 0;
	if(s[0] == s[2] && s[3] == s[5]){
		res += count(s[0], s[1], s[2]);
		res += count(s[3], s[4], s[5]);
	}
	else if(s[5] == s[1] && s[2] == s[4]){
		res += count(s[5], s[0], s[1]);
		res += count(s[2], s[3], s[4]);
	}
	else if(s[4] == s[0] && s[1] == s[3]){
		res += count(s[4], s[5], s[0]);
		res += count(s[1], s[2], s[3]);
	}
	else
		assert(0);
	printf("%d\n", res);
}

