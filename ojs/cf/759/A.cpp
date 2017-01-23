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
int s[MAXN], b[MAXN];
int mrk[MAXN];

void go(int u){
	mrk[u] = 1;
	if(mrk[s[u]] != 1)
		go(s[u]);
}

int main (){
	scanf("%d", &n);
	int sum = 0;
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &b[a]);
		sum += b[a];
	}
	int cnt = 0;
	for(int a=1;a<=n;a++){
		if(mrk[a])
			continue;
		go(a);
		cnt++;
	}
	if(cnt == 1) cnt = 0;
	int res = cnt + !(sum&1);
	printf("%d\n", res);
}
