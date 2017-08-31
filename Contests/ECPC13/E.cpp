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

int t, tc;

int main (){
	freopen("ghanophobia.in", "r", stdin);
	scanf(" %d", &t);
	while(t--){
		int e, g;
		scanf(" %d:%d", &e, &g);
		if(e + 1 == g + 6){
			e += 2;
			g = 6 + 2*g;
		} else {
			e += 1;
			g += 6;
		}
		printf("Case %d: ", ++tc);
		if(e == g)      puts("PENALTIES");
		else if(e < g)  puts("NO");
		else            puts("YES");
	}
}

