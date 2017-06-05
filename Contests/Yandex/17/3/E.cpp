#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
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

const int MAXN = 412;

int n, m, k;
int mrk[MAXN][MAXN][2];
int x, y, xx, yy;

queue<ppi> q;

pii s, t;


int has(pii p, int dir){
	return mrk[p.fst][p.snd][dir];
}

void bota(pii p, int dir, int dist){
	if(has(p, dir) != 0)
		return;
	q.push(ppi(p, dir));
	mrk[p.fst][p.snd][dir] = dist;
}

int vx[] = {0, 1, 0, -1};
int vy[] = {1, 0, -1, 0};

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < MAXN && y < MAXN);
}

int main (){
	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	x += 150;
	y += 150;
	xx += 150;
	yy += 150;
	s = pii(x, y);
	t = pii(xx, yy);
	bota(s, 1, 1);
	bota(s, 0, 1);

	while(!q.empty()){
		pii p = q.front().fst;
		int dir = q.front().snd;
		int dist = has(p, dir);
		q.pop();
		if(p == t){
			printf("%d\n", dist -1);
			return 0;
		}
		for(int d=0;d<4;d++){
			int nx = p.fst + vx[d];
			int ny = p.snd + vy[d];
			if((d&1) == dir) continue;	
			if(valid(nx, ny) && mrk[nx][ny][(d&1)] == 0){
				bota(pii(nx, ny), (d&1), mrk[p.fst][p.snd][dir] + 1);
			}
		}
	}
}
