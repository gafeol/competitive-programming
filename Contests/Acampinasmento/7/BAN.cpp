
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define fst first
#define snd second

typedef pair<int, int> pii;

typedef long long ll;

const int MAXN = 20004, MAXM = 202*15;
const int INF =  0x3f3f3f3f;

int n, k;

int v[MAXN], q[MAXN];

vector<pii> s;

int dp[MAXN][MAXM];
pii pre[MAXN][MAXM];

int res[MAXN];

void add(int x, int qtd){
	int val = v[x];
	if(qtd == 0) return ;
	s.pb(pii(val*qtd, x)); 
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", v+a); 
	for(int a=0;a<n;a++)
		scanf("%d", q+a);
	scanf("%d", &k);
	for(int i=0;i<n;i++){
		for(int k=0;;k++){
			if((1<<k)-1 > q[i]){
				k--;
				add(i, q[i] - (1<<k)+1);
				break;
			}
			if(k > 0)
				add(i, (1<<(k-1)));
		}
	}
	for(int a=0;a<=k;a++){
		for(int b=0;b<=s.size();b++){
			dp[a][b] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i=0;i<s.size();i++){
		int val = s[i].fst;
		if(i > 0){
			for(int a=0;a<=k;a++){
				dp[a][i] = min(dp[a][i], dp[a][i-1]);
				if(dp[a][i] == dp[a][i-1])
					pre[a][i] = pii(CHAR_MAX, -1);
			}
		}
		for(int a = k-val;a>=0;a--){
			if(dp[a][i] != INF){
				int id  = s[i].snd;
				int qtd = s[i].fst;
				dp[a + val][i+1] = min(dp[a + val][i+1], dp[a][i] + qtd/v[id]);
				if(dp[a + val][i+1]  == dp[a][i] + qtd/v[id]){
					pre[a+val][i+1] = s[i];
		//			printf("a %d i %d -> a+val %d i+1 %d pre %d %d\n", a, i, a+val, i+1, s[i].fst, s[i].snd);
				}
			}
		}
	}
	
	int i = s.size();
	for(int a=0;a<=k;a++){
		dp[a][i] = min(dp[a][i], dp[a][i-1]);
		if(dp[a][i] == dp[a][i-1])
			pre[a][i] = pii(-1, -1);
	}
	int u = k;
	i = s.size();
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
