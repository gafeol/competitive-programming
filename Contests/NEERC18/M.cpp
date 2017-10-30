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

int x, y;

int dist(int i, int j){
	return abs(x - i) + abs(y- j);
}

int n, m, k;
int s[MAXN];
int main (){
	int xx, yy;
	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	printf("%d\n", 4 + min(dist(xx-1, yy-1) + dist(xx+1, yy+1), dist(xx-1, yy+1) + dist(xx+1, yy-1)));
}

