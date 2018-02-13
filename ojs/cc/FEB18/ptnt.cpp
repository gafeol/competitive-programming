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

int n, m, x, k;
int cnt[3];
char s[MAXN];

int main (){
	for_tests(t, tt){
		cnt[0] = 0;
		cnt[1] = 0;
		scanf("%d %d %d %d",&n, &m, &x, &k);
		scanf(" %s", s);
		for(int a=0;a<k;a++){
			if(s[a] == 'O')
				cnt[1]++;
			else
				cnt[0]++;
		}
		for(int a=1;a<=m;a++){
			n -= min(x, cnt[(a&1)]);
			cnt[(a&1)] -= min(x, cnt[(a&1)]);
			if(n <= 0) break;
		}
		if(n <= 0)
			puts("yes");
		else
			puts("no");
	}
}
