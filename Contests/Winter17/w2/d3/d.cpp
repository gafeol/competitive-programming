#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int v[N], p[N];
const int inf = 0x3f3f3f3f;

bool magic() {
	int k = p[0] + p[1] + p[2];	
	for(int i = 0; i < 3; i++) {
		int l = p[3*i] + p[3*i+1] + p[3*i+2];	
		int c = p[i] + p[i+3] + p[i+6];	
		if(l != k) return false;
		if(c != k) return false;
	}
	int d = p[0] + p[4] + p[8];
	if(d != k) return false;
	d = p[2] + p[4] + p[6];
	if(d != k) return false;
	return true;		
}

int cost() {
	if(!magic()) return inf;
	int ans = 0;
	for(int i = 0; i < N; i++) ans += abs(v[i]-p[i]);
	return ans;
}

int main(){
	for(int i = 0; i < N; i++) {
		scanf("%d", v+i);	
		p[i] = i+1;
	}
	int ans = inf;
	do {
		ans = min(ans, cost());
	} while(next_permutation(p, p+N));
	printf("%d\n", ans);
}
