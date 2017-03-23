#include <bits/stdc++.h>
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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 58, MAXM = MAXN*MAXN;

int n, m, k;
int s[MAXN][MAXN], mrk[MAXN];

multiset<int> c[MAXN];
set<int> uni[MAXN];

queue <int> q;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		while(!q.empty())
			q.pop();
		for(int a=0;a<n;a++){
			c[a].clear();
			uni[a].clear();
			mrk[a] = 0;
			for(int b=0;b<n;b++){
				scanf("%d", &s[a][b]);
				if(s[a][b] == 0) continue;
				c[a].insert(s[a][b]);
				uni[a].insert(s[a][b]);
			}
		}
		if(n == 1){
			puts("1");
			continue;
		}
		for(int a=0;a<n;a++){
			if(uni[a].size() <= 1){
				q.push(a);
				mrk[a] = 1;
			}
		}
		int res = n;
		while(!q.empty()){
			res--;
			int u = q.front();
			q.pop();
			for(int v=0;v<n;v++){
				if(mrk[v]) continue;
				auto it = c[v].find(s[u][v]);
				if(it != c[v].end()){
					c[v].erase(it);
					it = c[v].find(s[u][v]);
					if(it == c[v].end())
						uni[v].erase(s[u][v]);
					if(uni[v].size() <= 1){
						q.push(v);
						mrk[v] = 1;
					}
				}
			}
		}
		printf("%d\n", res);	
	}
}
