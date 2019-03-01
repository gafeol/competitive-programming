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
char s[MAXN];

int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	bool ok = false;
	int i = n-1;

	for(int a=0;a<n-1;a++){

		if(s[a] > s[a+1]){
			ok = true;
			i = a;
			break;
		}
	}
	for(int a=0;a<n;a++){
		if(a == i) continue;
		printf("%c", s[a]);
	}
	puts("");
}

