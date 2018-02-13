#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define fst first
#define snd second

typedef pair<int, int> pii;

typedef long long ll;

const int MAXN = 20004, MAXM = 202;
const int INF =  0x3f3f3f3f;

int n, k;

int v[MAXN], q[MAXN];

int dp[MAXN][MAXM];
pii pre[MAXN][MAXM];

multiset<pii> us;  

int res[MAXN];

int add;

pii mn(){
	pii ans = (*us.begin());
	return pii(ans.fst+add, ans.snd);
}

void insere(pii x){
	printf("insere %d+%d %d\n", x.fst, add, x.snd);
	us.insert(pii(x.fst + add, x.snd));
}

void remove(pii x){
	printf("remove %d-%d %d\n", x.fst, add, x.snd);
	us.erase(us.find(pii(x.fst-add, x.snd)));
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", v+a); 
	for(int a=0;a<n;a++)
		scanf("%d", q+a);
	scanf("%d", &k);
	for(int a=0;a<=k;a++){
		for(int b=0;b<=n;b++){
			dp[a][b] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i=0;i<n;i++){
		int val = v[i];
		if(i > 0){
			for(int a=0;a<=k;a++){
				dp[a][i] = min(dp[a][i], dp[a][i-1]);
				if(dp[a][i] == dp[a][i-1])
					pre[a][i] = pii(-1, -1);
			}
		}
		for(int ini = k;ini > k-val;ini--){
			us.clear();
			for(int mult = 0;mult <= q[i] && ini-mult*val >= 0;mult++){
				int a = ini-mult*val;
				insere(pii(dp[a][i]+mult, a));
			}
			for(int mult = 0;ini - mult*val >= 0;mult++){
				int a = ini - mult*val;
				pii best = mn();
				dp[a][i+1] = best.fst; 
				pre[a][i+1] = pii(a - best.snd, i);
				remove(pii(dp[a][i], a)); 
				add--;
				if(a - (q[i]+1)*val >= 0)
					insere(pii(dp[a-(q[i]+1)*val][i] + q[i], a-(q[i]+1)*val));
			}
		}
	}
	
	int i = n;
	for(int a=0;a<=k;a++){
		dp[a][i] = min(dp[a][i], dp[a][i-1]);
		if(dp[a][i] == dp[a][i-1])
			pre[a][i] = pii(-1, -1);
	}
	int u = k;
	i = n;
	printf("%d\n", dp[k][i]);
	while(u > 0 && i >= 0){
		int id = pre[u][i].snd;
		int qtd = pre[u][i].fst;
		//	printf("u %d i %d id %d qtd %d\n", u, i, id, qtd); 
		if(id == -1){
			i--;
			continue;
		}
		//	printf("pre u %d %d %d\n", u, pre[u][i].fst, pre[u][i].snd);
		res[id] += qtd/v[id];
		u = u - pre[u][i].fst;
		i--;
	}
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
}
