#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1123456;

char s[MAXN];

int f[MAXN];

int main (){
	scanf(" %s", s);
	f[0] = -1;
	printf("0 ");
	int n = strlen(s);
	for(int a=1;a<n;a++){
		int ff = f[a-1];
		while(ff >= 0 &&  s[ff+1] != s[a])
			ff = f[ff];
		if(s[ff+1] == s[a])
			ff++;
		f[a] = ff;
		printf("%d ", f[a]+1);
	}
	puts("");
}
