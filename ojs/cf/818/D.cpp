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
int s[MAXN];
int A;
int nxt[MAXN];
int cnt[MAXN];
int mrk[MAXN];

int main (){
	scanf("%d %d", &n, &A);
	mrk[A] = 1;
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<n;a++){
		if(cnt[s[a]] < cnt[A])
			mrk[s[a]] = 1;
		cnt[s[a]]++;
	}
	for(int a=1;a<MAXN-10;a++){
		if(cnt[a] < cnt[A])
			mrk[a] = 1;
	}
	for(int a=1;a<MAXN-10;a++){
		if(mrk[a] == 0){
			printf("%d\n", a);
			return 0;
		}
	}
	puts("-1");
}
