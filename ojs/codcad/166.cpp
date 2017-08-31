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

const int MAXN = 2123;

int n, m, k;
int bit[MAXN][MAXN];

int qryy(int x, int y){
	y+=2;
	int ans =0;
	while(y < MAXN){
		ans = max(ans, bit[x][y]);
		y += (y&-y);
	}
	return ans;
}

int qry(int x, int y){
	x+=2;
	int ans = 0;
	while(x < MAXN){
		ans = max(ans, qryy(x, y));
		x += (x&-x);
	}
	return ans;
}

void updy(int x, int y, int val){
	y += 2;
	while(y > 0){
		bit[x][y] = max(bit[x][y], val);
		y -= (y&-y);
	}
}

void upd(int x, int y, int val){
	x+=2;
	while(x > 0){
		updy(x, y, val);
		x -= (x&-x);
	}
}

pii s[112345];

int main (){
	for_tests(t, tt){
		memset(bit, 0, sizeof(bit));
		scanf("%d", &n);
		int res =0;
		for(int a=0;a<n;a++){
			scanf("%d%d", &s[a].fst, &s[a].snd);
		}
		for(int a=n-1;a>=0;a--){
			int x = s[a].fst;
			int y = s[a].snd;
			int val = qry(x, y) + 1;
			res = max(res, val);
			upd(x, y, val);
		}
		printf("%d\n", res);
	}
}

