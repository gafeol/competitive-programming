#include <bits/stdc++.h>

using namespace std;

const int MAXN = 112;

int n, m;

int mrk[MAXN];

char s[MAXN][MAXN], mat[MAXN];

vector<int> v;

int main (){
	scanf("%d %d", &n, &m);
	for(int a=1;a<=n;a++){
		scanf(" %s", s[a]);
	}
	for(int a=0;a<m;a++){
		int i;
		scanf("%d", &i);
		mrk[i] = 1;
		v.push_back(i);
	}
	int vazio = 1;
	int sz;
	int fodeu = 0;
	for(int i: v){
		if(vazio){
			int tam = strlen(s[i]);
			for(int a=0;a<tam;a++){
				mat[a] = s[i][a];
			}
			sz = tam;
			vazio = 0;
		}
		else{
			int tam = strlen(s[i]);
			if(tam != sz){
				fodeu = 1;
				break;
			}
			for(int a=0;a<tam;a++){
				if(mat[a] != s[i][a])
					mat[a] = '?';
			}
		}
	}
	if(fodeu){
		puts("No");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(mrk[i] == 1) continue;
		int tam = strlen(s[i]);
		if(tam != sz) continue;
		int ok = 1;
		for(int a=0;a<sz;a++){
			if(mat[a] != '?' && s[i][a] != mat[a])
				ok = 0;
		}
		if(ok)
			fodeu = 1;
	}
	if(fodeu)
		puts("No");
	else
		puts("Yes");
	if(!fodeu){
		for(int a=0;a<sz;a++)
			printf("%c", mat[a]);
		puts("");
	}
}
