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

int vi(char c){
	if(c == 'U') return -1;
	if(c == 'D') return 1;
	return 0;
}

int vj(char c){
	if(c == 'L') return -1;
	if(c == 'R') return 1;
	return 0;
}

int main (){
	scanf("%d", &n);
	int i, j;
	i = j = 0;
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		i += vi(c);
		j += vj(c);
	}
	printf("%d\n", n - abs(i) - abs(j));
}

