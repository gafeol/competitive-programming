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
int s[MAXN], r[MAXN], l[MAXN], p[MAXN];

void test(int i){
	if(s[i] + l[i] + r[i] + r[(i+3)%4] + l[(i+1)%4] + s[(i+2)%4] != 0){
		puts("YES");
		exit(0);
	}
}

int main (){
	for(int a=0;a<4;a++){
		scanf("%d %d %d %d", &l[a], &s[a], &r[a], &p[a]);
	}
	for(int i = 0;i < 4;i++){
		if(p[i])
			test(i);
	}
	puts("NO");
}
