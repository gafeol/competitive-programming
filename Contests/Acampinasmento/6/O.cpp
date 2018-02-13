
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;

char p[MAXN];
char g[MAXN];
char s[2*MAXN];

int f[MAXN*2];

int main(){
	int n;
	scanf(" %s", p);
	scanf(" %s", g);
	n = strlen(p);
	reverse(g, g+n);
	reverse(p, p+n);
	strcat(s, g);
	strcat(s, "$");
	strcat(s, p);
	int tam = strlen(s);
	f[0] = -1;
	int mx = 0;
	
//	for(int i=0;i<tam;i++)
//		printf("%c ", s[i]);
//	puts("");
//	printf("-1 ");
	
	for(int	i=1;i<tam;i++){
		int ff = f[i-1];
		while(ff >= 0 && s[ff+1] != s[i])
			ff = f[ff];
		if(s[ff+1] == s[i]) ff++;
		f[i] = ff;
	//	printf("%d ", f[i]);
	}
	//puts("");
	printf("%d\n", n-f[tam-1]-1);

}
