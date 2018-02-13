
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1123456;

char s[MAXN], v[MAXN];
int ff[MAXN];
int n;

int main (){
	scanf(" %s", s);
	n = strlen(s);
	ff[0] = -1;
	v[0] = s[n-1];
	for(int a=1;a<n;a++){		
		v[a] = s[n-1-a];
		int f = ff[a-1];
		while(f >= 0 && s[f+1] != s[a])
			f = ff[f];
		if(s[f+1] == s[a])
			 f++;
		ff[a] = f;
	}
	int i = -1;
	for(int j=0;j<n;j++){
		if(s[i+1] == v[j]){
			i++;
			continue;
		}
		while(i >= 0 && s[i+1] != v[j])
			i = ff[i];
		if(s[i+1] == v[j])
			i++;
	}
	printf("%d\n", i+1);
}

