#include <bits/stdc++.h>
using namespace std;

const int MAXN = 120;

int mrk[MAXN][MAXN];

string w[] = {"NORTH", "SOUTH", "EAST", "WEST"};
int vi[] = {-1, 1, 0, 0};
int vj[] = {0, 0, 1, -1};

char s[MAXN];

void go(int i, int j, int ld){
	mrk[i][j] = 1;
	if(ld != -1){
		scanf(" %s", s);
		if(strcmp(s, "BLOCKED") == 0)
			return ;
	}
	for(int d=0;d<4;d++){
		int ni = i + vi[d]; 
		int nj = j + vj[d];
		if(mrk[ni][nj]) continue;
		cout << w[d] << endl;
		fflush(stdout);
		go(ni, nj, d);
	}

	if(ld == -1)
		return ;
	cout << w[ld^1] << endl;
	fflush(stdout);
	scanf(" %s", s);
}

int main (){
	int i = 50, j = 50;	
	go(i, j, -1);
	puts("DONE");
	fflush(stdout);
}
