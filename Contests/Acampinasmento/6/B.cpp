#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

int n;
int s[MAXN], pai[MAXN], sz[MAXN];


int raiz(int u){
	if(pai[u] == u) return u;
	return pai[u] = raiz(pai[u]);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j) return ;
	if(sz[i] > sz[j]) swap(i, j);
	pai[i] = j;
	sz[j] += sz[i];
}
int z[MAXN];

int main (){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		pai[i] = i;
		sz[i] = 1;
		scanf("%d", s+i);
		if(s[i] != 0)
			join(i, s[i]);
	}
	for(int a=0;a<n;a++){
		s[a] = raiz(a+1);
	}	
	

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
