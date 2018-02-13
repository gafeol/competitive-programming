#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 8002;

int f[MAXN];

char s[MAXN];

int main(){
	scanf(" %s", s);
	int n = strlen(s);

	ll res =0;
	for(int i=0;i<n;i++){
		f[i] = i-1;
		res++;
		for(int j=i+1;j<n;j++){
			int ff = f[j-1];	
			while(ff >= i && s[j] != s[ff+1])
				ff = f[ff];
			if(s[j] == s[ff+1])
				ff++;
			f[j] = ff;
			res += (j - f[j]-1 - i + 1);
			printf("i %d f[%d] %d\n", i, j, f[j]);
			printf("i %d j %d res += %d\n", i, j, (j -f[j]-1 - i + 1));
		}
	}
	printf("%lld\n", res);
}
