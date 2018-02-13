#include <bits/stdc++.h> 
using namespace std;

typedef pair<int, int> pii;


const int MAXN = 110;

int d[MAXN][MAXN], mrk[MAXN][MAXN];
pii pr[MAXN][MAXN];

int vx[] = {1, 1, -1, -1};
int vy[] = {-1, 1, -1, 1};
int m, n, p, q, x, y, xx, yy;

bool valid(int x, int y){
	return (x >= 1 && y>= 1 && x <= m && y <= n);
}

queue<pii> Q;

int main (){
	scanf("%d%d%d%d", &m, &n, &p, &q);
	scanf("%d%d%d%d", &x, &y, &xx, &yy);
	pr[x][y] = pii(-1, -1);
	d[x][y] = 0;
	mrk[x][y] = 1;
	Q.push(pii(x, y));
	while(!Q.empty()){
		pii u = Q.front();
		Q.pop();
		x = u.first;
		y = u.second;
		for(int a=0;a<4;a++){
			int nx = x + p*vx[a];
			int ny = y + q*vy[a];
			if(valid(nx, ny) && !mrk[nx][ny]){
				Q.push(pii(nx, ny));	
				mrk[nx][ny] = 1;
				d[nx][ny] = d[x][y] + 1;
				pr[nx][ny] = pii(x, y);
			}
		}
		swap(p, q);
		for(int a=0;a<4;a++){
			int nx = x + p*vx[a];
			int ny = y + q*vy[a];
			if(valid(nx, ny) && !mrk[nx][ny]){
				Q.push(pii(nx, ny));	
				mrk[nx][ny] = 1;
				d[nx][ny] = d[x][y] + 1;
				pr[nx][ny] = pii(x, y);
			}
		}
		swap(p, q);
	}
	stack<pii> st;
	if(mrk[xx][yy]){
		printf("%d\n", d[xx][yy]);
		while(valid(xx, yy)){
			st.push(pii(xx, yy));
			int ax = xx;
			int ay = yy;
			xx = pr[ax][ay].first;
			yy = pr[ax][ay].second;
		}
		while(!st.empty()){
			pii u = st.top();
			st.pop();
			printf("%d %d\n", u.first, u.second);
		}
	}
	else
		puts("-1");
}
