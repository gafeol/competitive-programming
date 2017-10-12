
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define pb push_back

const int MAXN = 412345, MAXM = 1123456;


int n, m;

int d[MAXN][3], indeg[MAXN], outdeg[MAXN];
int mrk[MAXN];

int S, T;

pii ar[MAXM];

int ori[MAXM];

vector<int> adj[MAXN];
queue<int> q;

void bfs(int u, int t){
	for(int a=0;a<=n;a++)
		mrk[a] = 0;
	d[u][t] = 0;
	q.push(u);
	mrk[u] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nxt: adj[u]){
			if(!mrk[nxt]){
				d[nxt][t] = d[u][t] + 1;
				mrk[nxt] = 1;
				q.push(nxt);
			}
		}
	}
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &m, &S, &T);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			indeg[a] = 0;
			outdeg[a] = 0;
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j); 
			ar[a].fst = i;
			ar[a].snd = j;
			adj[i].pb(j);
			adj[j].pb(i);
		}
		bfs(S, 0);
		bfs(T, 1);
		for(int a=0;a<m;a++){
			if(ar[a].fst > ar[a].snd)
				swap(ar[a].fst, ar[a].snd);
			if(d[ar[a].fst][0] < d[ar[a].fst][1]){
				ori[a] = 1;
				indeg[ar[a].snd]++;
				outdeg[ar[a].fst]++;
			}
			else{
				ori[a] = 0;
				indeg[ar[a].fst]++;
				outdeg[ar[a].snd]++;
			}
		}
		int fodeu = 0;
		for(int a=1;a<=n;a++){
			if(a == S || a == T) continue;
			if(indeg[a] > 0 && outdeg[a] > 0)
				1;
			else{
				fodeu = 1;
			}
		}
		if(fodeu){
			puts("No");
			continue;
		}
		else
			puts("Yes");
		for(int a=0;a<m;a++){
			if(ori[a])
				printf("%d %d\n", ar[a].fst, ar[a].snd);
			else
				printf("%d %d\n", ar[a].snd, ar[a].fst);
		}
	}
}
