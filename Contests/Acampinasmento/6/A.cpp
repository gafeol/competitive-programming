#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1123456;

char s[MAXN];

int p[MAXN], z[MAXN];

int n;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", z+a);
		p[a+z[a]-1] = max(z[a], p[a+z[a]-1]);
	}
	for(int a=n-1;a>=0;a--){
		p[a] = max(p[a], p[a+1]-1);
	}
	for(int a=0;a<n;a++)
		printf("%d ", p[a]);
}
