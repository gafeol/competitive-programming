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
	scanf("%d %d", &n, &k);
	k--;
	int z = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(!s[a])
			z++;
	}
	int res = 0;
	if(s[k] != 0){
		s[k] = 0;
		res++;
	}
	else
		z--;
	res += z;
	sort(s, s+n);
	int val;
	int j = n;
	for(int a=1;a<j;a++){
		if(s[a] == s[a-1] || s[a] == s[a-1]+1) continue;
		val = s[a-1];
		val += min(z, (s[a] - s[a-1])-1);
		z -= min(z, (s[a] - s[a-1]) - 1);
		if(val >= s[a]-1) continue;
		while(val < s[a]-1 && a < j){
			val++;
			j--;
			res++;
			debug("comi cara %d por %d\n", s[j], s[a]);
		}
	}
	printf("%d\n", res);

}

