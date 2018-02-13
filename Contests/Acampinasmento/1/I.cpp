#include <bits/stdc++.h>
using namespace std;

int n, h;

const int MAXN = 5123;

int nxt[MAXN];
int v[MAXN];

vector<int> s;

int bit[MAXN];

void put(int u, int k){
	if(k == 0){
		nxt[u] = h;
		h = u;
		return ;
	}
	k--;
	int v = h;
	while(k--)
		v = nxt[v];	

	nxt[u] = nxt[v]; 
	nxt[v] = u;	
}

int qry(int i){
	i += 2;
	int ans = 0;
	while(i > 0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

void upd(int i){
	i += 2;
	while(i < MAXN){
		bit[i]++;
		i += (i&-i);
	}
}

int main(){
	int x;
	h = -1;
	memset(nxt, -1, sizeof(nxt));
	while(scanf("%d", &x) != EOF)
		s.push_back(x);	
	n = s.size();
	for(int i=n-1;i>=0;i--){
		put(i+1, s[i]);
	}
	int u = h;
	for(int i=0;i<n;i++){
		v[i] = u;
		u = nxt[u];
	}
	stack<int> st;
	for(int i=n-1;i>=0;i--){
		st.push(qry(v[i]));
		upd(v[i]);
	}
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}
