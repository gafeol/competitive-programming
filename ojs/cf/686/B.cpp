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
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=1;a<=n;a++){
		int mn = INT_MAX;
		int imn;
		for(int b=a;b<=n;b++){
			if(s[b] < mn){
				mn = s[b];
				imn = b;
			}
		}
		while(imn > a){
			printf("%d %d\n", imn-1, imn);
			swap(s[imn-1], s[imn]);
			imn--;
		}
	}
}
