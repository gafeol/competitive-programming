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
int s[MAXN], mrk[MAXN][MAXN];
char M[MAXN][MAXN];
queue<pii> q;

int vi[] = {0, 0, -1, 1};
int vj[] = {1, -1, 0, 0};

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '*' && M[i][j] != '<' && M[i][j] != '>' && M[i][j] != '^' && M[i][j] != 'v');
}

bool uniq(int i, int j){
	int cnt = 0;
	for(int d=0;d<4;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];
		cnt += !valid(ii, jj);
	}
	if(cnt == 4){
		puts("Not unique");
		exit(0);
	}
	return (cnt > 2);
}


char put(int d){
	if(d == 0)
		return '<';
	else if(d == 1)
		return '>';
	else if(d == 2)
		return 'v';
	else
		return '^';
}

void check(int i, int j){
	for(int d=0;d<4;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];
		if(valid(ii, jj)){
			if(uniq(ii, jj) && mrk[ii][jj] == 0){
				mrk[ii][jj] = 1;
				q.push(pii(ii, jj));
			}
		}
	}
}

void go(int i, int j){
	for(int d=0;d<4;d++){
		int ii = i + vi[d];
		int jj = j + vj[d];
		if(valid(ii, jj)){
			debug("em %d %d bota %c\n", i, j, put(d));
			debug("em %d %d bota %c\n", ii, jj, put(d^1));
			M[i][j] = put(d);
			M[ii][jj] = put(d^1);
			check(i, j);
			check(ii, jj);
			break;
		}
	}
	if(M[i][j] == '.'){
		puts("Not unique");
		exit(0);
	}
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(valid(i, j) && uniq(i, j)){
				mrk[i][j] = 1;
				q.push(pii(i, j));
			}
		}
	}
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		int i = top.fst;
		int j = top.snd;
		if(M[i][j] == '<' || M[i][j] == '>')
			continue;
		go(i, j);	
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == '.'){
				puts("Not unique");
				return 0;
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			printf("%c", M[a][b]);
		}
		printf("\n");
	}
}
