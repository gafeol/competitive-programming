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

ll tot = 0;

int ceil(int a, int b){
	return a/b + (a%b != 0);
}

int valid(int x){
	return (x == tot/n || x == ceil(tot, n));
}

ll res;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		tot += s[a];
	}
	sort(s, s+n);
	int cred = tot%n;
	for(int a=0;a<n;a++){
		if(s[a] <= tot/n) continue;
		if(cred){
			cred--;
			res += s[a] - ceil(tot, n);
		}
		else{
			res += s[a] - tot/n;
		}
	}
	printf("%lld\n", res);
}

