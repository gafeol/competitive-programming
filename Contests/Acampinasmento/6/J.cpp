#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1123456;

char s[MAXN];

int p[MAXN], z[MAXN];

int n;
int f[MAXN];

int main(){
	while(scanf(" %s", s) != EOF){
		int n = strlen(s);
		f[0] = -1;
		for(int a=1;a<n;a++){
			int ff = f[a-1];
			while(ff >= 0 && s[ff+1] != s[a])
				ff = f[ff];
			if(s[a] == s[ff+1])
				ff++;
			f[a] = ff;
		}
		for(int a=0;a<n-f[n-1]-1;a++){
			printf("%c", s[a]);
		}
		puts("");
	}
}
