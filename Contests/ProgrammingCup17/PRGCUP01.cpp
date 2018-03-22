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

const int MAXN = 25;

int n, m, k;
int s[MAXN];
int mrk[MAXN][MAXN];

int vi[] = {-1, -2, -2, -1, +1, +2, +2, +1};
int vj[] = {-2, -1, +1, +2, +2, +1, -1, -2};

queue<pii> q;

bool valid(int i, int j){
	return (i >= 1 && j>=1 && i < 9 && j < 9);
}

void go(int i, int j){
	mrk[i][j] = 1;
	q.push(pii(i, j));
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		i = top.fst;
		j = top.snd;
		for(int a=0;a<8;a++){
			int ii = i + vi[a];
			int jj = j + vj[a];
			if(valid(ii, jj) && !mrk[ii][jj]){
				mrk[ii][jj] = mrk[i][j] + 1;
				q.push(pii(ii, jj));
			}
		}
	}
}

int main (){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		char c, cc;
		int i, j, ii, jj;
		scanf(" %c%d %c %d", &c, &j, &cc, &jj);
		i = c - 'a' + 1;
		ii = cc - 'a' + 1;
		go(i, j);
		printf("%d\n", mrk[ii][jj]-1);
	}
}

