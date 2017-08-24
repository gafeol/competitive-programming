#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n;
int memo[N][N][N], vis[N][N][N], memo2[N][N], vis2[N][N];
int a[N], b[N], c[N], turn;
int *s, *t;

int dp(int i, int j, int k) {
	if(i == n || j == n || k == n) return 0;	
	int &me = memo[i][j][k];
	if(vis[i][j][k] == turn) return me;
	vis[i][j][k] = turn;
	me = 0;
	if(a[i] == b[j] && b[j] == c[k]) me = max(me, 1 + dp(i+1, j+1, k+1));
	me = max(me, dp(i+1, j, k));
	me = max(me, dp(i, j+1, k));
	me = max(me, dp(i, j, k+1));
	return me;
}

int dp2(int i, int j) {
	if(i == n || j == n) return 0;
	int &me = memo2[i][j];
	if(vis2[i][j] == turn) return me;
	vis2[i][j] = turn;
	me = 0;
	if(a[i] == b[j]) me = 1 + dp2(i+1, j+1);
	me = max(me, dp2(i+1, j));
	me = max(me, dp2(i, j+1));
	return me;
}

int main(int argc, char **argv) {
	cin >> n;	
	srand(time(NULL));
	turn++;
	for(int i = 0; i < n; i++) {
		a[i] = rand() % n + 1;
		b[i] = rand() % n + 1;
		c[i] = rand() % n + 1;
	}
	cout << "de 3: " << dp(0, 0, 0) << endl;
	int mn = 1209834;
	
	s = a;
	t = b;
	turn++;
	mn = min(mn, dp2(0, 0));

	t = c;
	turn++;
	mn = min(mn, dp2(0, 0));

	s = b;
	turn++;
	mn = min(mn, dp2(0, 0));

	cout << "de 2: " << mn << endl;
}
