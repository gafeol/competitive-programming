#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1123456;

char s[MAXN];

int z[MAXN];

int main (){
	scanf(" %s", s);
	int n = strlen(s);
	z[0] = 0;
	printf("0 ");
	int L = 0, R = 0;
	for(int i =1;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && s[R] == s[R - L])
				R++;
			z[i] = R - L;
			R--;
		}
		else{
			if(z[i-L] >= R - i + 1){
				L = i;
				while(R < n && s[R] == s[R-L])
					R++;
				z[i] = R - L;
				R--;
			}
			else
				z[i] = z[i-L];
		}
		printf("%d ", z[i]);
	}
	puts("");
}
