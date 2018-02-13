#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 112345;

int n;
int ind[MAXN];
int res[MAXN];

ll s[MAXN];

bool cmp(int i, int j){
	return s[i] > s[j];
}

int main (){
	freopen("hell.in", "r", stdin);
	freopen("hell.out", "w", stdout);
	scanf("%d", &n);
	ll sum = 0;
	for(int a=0;a<n;a++){
		scanf("%lld", &s[a]);
		sum += s[a];
		ind[a] = a;
	}
	if((sum&1)){
		puts("No");
		return 0;
	}
	sum = sum/2;
	sort(ind, ind+n, cmp);
	for(int a=0;a<n;a++){
		int i = ind[a];
		if(sum >= s[i]){
			sum -= s[i];
			res[i] = 2;
		}
	}
	if(sum == 0){
		puts("Yes");
		for(int a=0;a<n;a++){
			res[a]--;
			printf("%d ", res[a]);
		}
		puts("");
	}
	else
		puts("No");
}
