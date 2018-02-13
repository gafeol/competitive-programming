#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112;

char sig[MAXN][15];
char nam[MAXN][40];

map<string, int> cnt;

vector<int> ans;

int n;
int main(){
	scanf("%d", &n);
	int res = 0;
	for(int a=0;a<n;a++){
		scanf(" %s %s", sig[a], nam[a]); 
		if(strcmp(sig[a], "SCH") == 0) continue;
		int mx = 2;
		if(strcmp(sig[a], "MSU") == 0)
			mx = 4;
		if(cnt[sig[a]] < mx && ans.size() < 10){
			ans.push_back(a);
			cnt[sig[a]]++;
		}
	}
	printf("%d\n", ans.size());
	for(int i: ans){
		printf("%s %s\n", sig[i], nam[i]);
	}
}
