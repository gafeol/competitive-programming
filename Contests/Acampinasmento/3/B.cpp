
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 265;

vector<int> e; 

typedef pair<int, int> pii;

vector<pii> p;

map<int, int> cnt;

int A, B, C, f, n, m;

bool cmp(int a, int b){
	return cnt[a] > cnt[b];
}

bool cmp2(pii a, pii b){
	return a > b;
}

int res[MAXN*MAXN];

int main (){
	scanf("%d%d%d%d", &f, &A, &B, &C);
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			int x;
			scanf("%d", &x); 
			cnt[x]++;
			e.push_back(x);
		}
	}
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());
	for(int a=0;a<e.size();a++){
		p.push_back(pii(f, a));
		f = ((A*f)+B)%C+1;
	}
	sort(p.begin(), p.end(), cmp2); 
	sort(e.begin(), e.end(), cmp);
	for(int i=0;i<p.size();i++){
		res[p[i].second] = e[i];
	}
	printf("%d\n", (int)e.size());
	for(int a=0;a<e.size();a++)
		printf("%d ", res[a]);
}

