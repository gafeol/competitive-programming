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

int n, m, k, cnt[MAXN];
char s[MAXN];
int sum[MAXN];
int mrk[MAXN];


int main (){
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	scanf(" %s", s+1);
	ll res = 0;
	n = strlen(s+1);
	for(int a=1;a<=n;a++){
		if(mrk[s[a]] == 0){
			mrk[s[a]] = a;
		}
		else{
			for(int b='A';b<='Z';b++){
				if(mrk[b] > mrk[s[a]])
					res++;
			}
			mrk[s[a]] = 0;
		}
	}
	printf("%lld\n", res);
}
