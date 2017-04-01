#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }

const int MAXN = 212345;

const int HORA = 3601, INF = 0x3f3f3f3f;

int n, m, k;
int dp[MAXN], s[MAXN];
queue<int> q;

void cmp(int u, int nxt){
	if(nxt >= HORA)
		nxt = HORA-1;
	if(nxt < 0)
		nxt = 0;
	
	if(dp[nxt] > dp[u] + 1){
		dp[nxt] = dp[u] + 1;
		q.push(nxt);
	}
}

int main (){
	for_tests(t, tt){
		memset(dp, INF, sizeof(dp));
		scanf("%d %d", &n, &k);
		for(int a=0;a<n;a++){
			scanf("%d", s+a);
		}
		q.push(0);
		dp[0] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int a=0;a<n;a++){
				cmp(u, u+s[a]); 
			}
		}
		for(int a=k;a<HORA;a++){
			if(dp[a] != INF){
				printf("%d %d\n", dp[a], a - k);
				break;
			}
		}
	}
}
