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
	int fodeu = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(s[a] > 100){
			fodeu = 1;
		}
	}
	if(fodeu){
		puts("No");
		return 0;
	}
	if(n == 1 && s[0] == 100){
		puts("Yes");
		return 0;
	}
	double mn = 0;
	for(int a=0;a<n;a++){
		mn += max(0., (s[a] - 0.5));
	}
	double mx = 0;
	for(int a=0;a<n;a++){
		mx += min(100., (s[a] + 0.5));
	}
	if(mn > 100. || mx <= 100.){
		puts("No");
		return 0;
	}
	puts("Yes");
}
