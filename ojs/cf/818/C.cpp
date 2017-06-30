

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

const int MAXN = 112345;

int n, m, k, ns;

int cnt[MAXN];

struct sofa{
	int x, y, xx, yy;
	sofa(){}
	sofa(int x1, int y1, int xx1, int yy1){
		x = x1;
		y = y1;
		xx = xx1;
		yy = yy1;
	}
} s[MAXN];

int bit[MAXN][4];

void upd(int i, int t){
	i+=2;
	while(i < MAXN){
		bit[i][t]++;
		i += (i&-i);
	}
}

int qry(int i, int t){
	i+=2;
	int ans = 0;
	while(i > 0){
		ans += bit[i][t];
		i -= (i&-i);
	}
	return ans;
}

int main (){
	scanf("%d", &ns);
	scanf("%d %d", &n, &m); 
	for(int a=0;a<ns;a++){
		int x, xx, y, yy;
		scanf("%d%d%d%d", &x, &y, &xx, &yy);	
		upd(min(x, xx), 0);
		upd(max(x, xx), 1);
		upd(min(y, yy), 2);
		upd(max(y, yy), 3);
		s[a] = sofa(x, y, xx, yy);
	}
	scanf("%d %d %d %d", &cnt[0], &cnt[1], &cnt[2], &cnt[3]);
	int res = -1;
	for(int a=0;a<ns;a++){
		int x = s[a].x;
		int xx = s[a].xx;
		int y = s[a].y;
		int yy = s[a].yy;
		debug("cnt[0] %d == qry(%d, 0) %d\n", cnt[0], max(x, xx), qry(max(x, xx)-1, 0)-(x != xx)); 
		debug("cnt[1] %d == qry(%d, 1) %d\n", cnt[1], min(x, xx), qry(MAXN-5, 1) - qry(min(x, xx), 1)- (x != xx)); 
		debug("cnt[2] %d == qry(%d, 2) %d\n", cnt[2], max(y, yy), qry(max(y, yy)-1, 2)-(y != yy)); 
		debug("cnt[3] %d == qry(%d, 3) %d\n", cnt[3], min(y, yy), qry(MAXN-5, 3) - qry(min(y, yy), 3)- (y != yy)); 
		if(qry(max(x, xx)-1, 0)-(x!= xx) == cnt[0] && qry(MAXN-5, 1) - qry(min(x, xx), 1)-(x!=xx) == cnt[1] && qry(max(y, yy)-1, 2)-(y != yy)==cnt[2] && qry(MAXN-5, 3) - qry(min(y, yy), 3)-(y != yy)==cnt[3]){
			res = a+1;
			debug("deu certo %d\n", a+1);
		}
	}
	printf("%d\n", res);
}
