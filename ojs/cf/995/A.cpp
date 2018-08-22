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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m, k;
int s[MAXN];

int M[5][MAXN];

pii ini[MAXN];
pii fim[MAXN];

int mrk[5][MAXN];

int ok[MAXN];

vector<int> res[5];

bool valid(int i, int j){
	return (i >=0 && j >=0 && i < 4 && j < m);
}

vector<pii> q;

/*
void go(int c, int i, int j){
	mrk[i][j] = 1;
	if(fim[c].fst == i && fim[c].snd == j){
		ok[c] = 1;
		q.pb(pii(i, j));
		return ;
	}
	for(int d=0;d<4;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];
		if(valid(c, ii, jj) && !mrk[ii][jj])
			go(c, ii, jj);
		if(ok[c]){
			q.pb(pii(i, j));
			return ;
		}
	}
}*/


void move(int c, pii a, pii b){
	debug("try move %d %d %d\n", c, b.fst+1, b.snd+1);
	if(c == 0) return ;
	int i = a.fst;
	int j = a.snd;
	int ii = b.fst;
	int jj = b.snd;
	if(!valid(ii, jj)) return ;
	if(M[ii][jj] != c && M[ii][jj] != 0) return ;
	M[i][j] = 0;
	M[ii][jj] = c;
	res[0].pb(c);
	res[1].pb(ii);
	res[2].pb(jj);
	ini[c] = pii(ii, jj);
	debug("move %d %d %d\n", c, ii+1, jj+1);
}

int cnt;

void check(){
	for(int a=1;a<=k;a++){
		if(pii(ini[a].fst + 1, ini[a].snd) == fim[a]){
			cnt++;
			move(a, ini[a], fim[a]);
		}
		else if(pii(ini[a].fst - 1, ini[a].snd) == fim[a]){
			cnt++;
			move(a, ini[a], fim[a]);
		}
	}
}

pii findEmpty(){
	for(int a=1;a<3;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == 0){
				return pii(a, b);
			}
		}
	}
	return pii(-1, -1);
}

void print(){
	return ;
	for(int a=0;a<4;a++){
		for(int b=0;b<m;b++){
			printf("%d ", M[a][b]);
		}
		puts("");
	}
}

int main (){
	scanf("%d%d", &m, &k);
	for(int a=0;a<4;a++){
		for(int b=0;b<m;b++){
			scanf("%d", &M[a][b]);
			if(a == 0 || a == 3)
				fim[M[a][b]] = pii(a, b);
			else
				ini[M[a][b]] = pii(a, b);
		}
	}
	while(cnt < k){
		check();		
		pii emp = findEmpty();
		if(emp.fst == -1){
			puts("-1");
			return 0;
		}
		move(M[1][0], pii(1, 0),  pii(2, 0));
		for(int a=1;a<m;a++)
			move(M[1][a], pii(1, a), pii(1, a-1));

		check();		

		move(M[2][m-1], pii(2, m-1), pii(1, m-1));
		for(int a=m-1;a>1;a--){
			move(M[2][a-1], pii(2, a-1), pii(2, a));
		}
		print();
		check();		
		move(M[2][0], pii(2, 0), pii(2, 1));
		print();
		/*
		int i = emp.fst;
		int j = emp.snd;
		if(i == 1){
			while(j > 0){
				move(M[i][j-1], i, j);
				j--;
			}
			move(M[2][0], 1, 0);
			i = 2;
			while(j < m-1){
				move(M[i][j+1], i, j);
				j++;
			}
			move(M[1][m-1], 2, m-1);
			i = 1;
			assert(j == m-1);
			while(j-1 > emp.snd){ 
				move(M[i][j-1], i, j);
				j--;
			}
		}
		else{
			while(j+1 <= m-1){
				move(M[i][j+1], i, j);
				j++;
			}
			move(M[1][m-1], 2, m-1);
			i = 1;
			j = m-1;
			while(j-1 >= 0){
				move(M[i][j-1], i, j); j--;
			}
			if(emp.snd != 0)
				move(M[2][0], 1, 0);
			i = 2;
			while(j+1 < emp.snd){
				move(M[i][j+1], i, j);
				j++;
			}
		}
		*/
	}
	if(res[0].size() > 20000){
		puts("-1");
		return 0;
	}
	printf("%d\n", res[0].size());
	for(int a=0;a<res[0].size();a++){
		printf("%d %d %d\n", res[0][a], res[1][a]+1, res[2][a]+1);

	}
}

