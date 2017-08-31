#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

int n, m, k;
int s[MAXN], res[MAXN];

int main (){
	freopen("cubes.in", "r", stdin);
	int t;
	
	scanf("%d", &t);
	int tt = 0;
	while(t--){
		tt++;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		sort(s, s+n);
		int i = 0, j = n-1;
		int cnt = n-1;
		for(int a=n-1;a>=0;a--){
			res[j] = s[a];
			j--;
			a--;
			if(a < 0) break;
			res[i] = s[a];
			i++;
		}
		printf("Case %d:\n", tt);
		for(int a=0;a<n;a++){
			printf("%d%c", res[a], " \n"[a+1 == n]);
		}
	}
}

