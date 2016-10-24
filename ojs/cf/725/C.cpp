#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
char s[MAXN];


map<char, int> ind;

vector<int> adj[1000];

int cnt[5];


int bm[10][30];
char M[10][30];
int id, fd, xi, xj;
char d;

vector<char> let[3];

int ii[3];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i <=1 && j <13);
}

void botabef(int i, int j){
	for(char ch: let[ii[0]]){
		M[i][j] = ch;
		bm[i][j] = 1;
		if(i == 0)
			i = 1;
		else{
			i = 0;
			j++;
		}
	}
	xi = i;
	xj = j;
}

int vi[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int vj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int mi[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int mj[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

void bota1(){
	int i, j;
	for(int a=0;a<8;a++){
		if(valid(xi + vi[a], xj + vj[a]) && M[xi + vi[a]][xj + vj[a]] == ' '){
			i = xi + vi[a];
			j = xj + vj[a];
			break;
		}
	}	
	for(int b=0;b<let[ii[1]].size();b++){
		char ch = let[ii[1]][let[ii[1]].size()-b-1];
		M[i][j] = ch;
		if(valid(i, j+1) && M[i][j+1] == ' '){
			j++;
		}
		else if((valid(i-1, j) && M[i-1][j] == ' ') || (valid(i+1, j) && M[i+1][j] == ' ')){
			if(valid(i-1, j) && M[i-1][j] == ' ')
				i--;
			else
				i++;
		}
		else
			j--;
	}
}

void win(){
	for(int a=0;a<2;a++){
		for(int b=0;b<13;b++){
			printf("%c", M[a][b]);
		}
		printf("\n");
	}
	exit(0);
}

void zera(){
	for(int a=0;a<2;a++){
		for(int b=0;b<13;b++){
			M[a][b] = ' ';
		}
	}
}

void bota2(){
	if(let[ii[2]].size() == 0)
		win();
	int i, j;
	i = -1;
	j = -1;
	for(int a=0;a<8;a++){
		if(valid(xi + vi[a], xj + vj[a]) && M[xi + vi[a]][xj + vj[a]] == ' '){
			i = xi + vi[a];
			j = xj + vj[a];
			break;
		}
	}
	if(i == -1){
		zera();
	}
	else{
		for(char ch: let[ii[2]]){
			M[i][j] = ch;
			for(int a=0;a<9;a++){
				int ai = i + mi[a], aj = j + mj[a];
				if(valid(i + mi[a], j + mj[a]) && M[i+mi[a]][j+mj[a]] == ' '){
					i = ai;
					j = aj;
					break;
				}
			}
		}
		win();
	}
}

void fixbef(int i, int j){
	int dir = -1;
	for(char ch: let[ii[0]]){
		M[i][j] = ch;
		if(valid(i, j+dir))
			j+=dir;
		else{
			if(valid(i+1, j))
				i++;
			else
				i--;
			dir = 1;
		}
	}
}

void tenta(){
//	printf("TENTATIVAA:\n");
//	for(int i=0;i<3;i++){
//		for(char c: let[ii[i]]){
//			printf("%c ", c);
//		}
//		printf("\n");
//	}
	botabef(0, 0);
	if(valid(xi-1, xj))
		fixbef(xi-1, xj);
	else
		fixbef(xi, xj-1);
	M[xi][xj] = d;
	bota1();
	bota2();

}

int main (){
	scanf(" %s", s);
	int n = 27;
	zera();
	int bef, bet, aft;
	bef = bet = aft = 0;
	for(int a=0;a<n;a++){
		if(a != 0){
			adj[a].pb(s[a-1]);
		}
		if(a != n-1)
			adj[a].pb(s[a+1]);
		ind[s[a]]++;
		if(ind[s[a]] == 2)
			d = s[a];
	}
	int mrk = 0;

	for(int a=0;a<n;a++){
		if(s[a] == d){
			if(mrk == 0)
				id = a;
			fd = a;
			mrk++;
			continue;
		}
		if(!mrk)
			bef++;
		else if(mrk == 1)
			bet++;
		else
			aft++;
		let[mrk].pb(s[a]);
		cnt[mrk]++;
	}
	ii[0] = 1;
	ii[1] = 0;
	ii[2] = 2;
	if(let[1].size()!=0){
		
		zera();
		tenta();
	}
	printf("Impossible\n");
}
