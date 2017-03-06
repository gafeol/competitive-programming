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

const int MAXN = 212345;

int n, m, k;
int deg[MAXN];
char nm[MAXN][30], ct[MAXN][30], s[MAXN][2][30];
map<string, int> mrk, ind;
int res;

bool ig(int i, int j){
	return strcmp(s[i][deg[i]], s[j][deg[j]]) == 0;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s %s", s[a][0], s[a][1]);
		s[a][0][3] = '\0';
		s[a][1][3] = '\0';
		s[a][1][2] = s[a][1][0];
		s[a][1][1] = s[a][0][1];
		s[a][1][0] = s[a][0][0];
	}
	queue<int> q;
	for(int a=0;a<n;a++){
		if(deg[a] == 1) continue;
		for(int b=0;b<n;b++){
			if(a == b) continue;
			if(strcmp(s[a][0], s[b][deg[b]]) == 0){
				if(deg[a] == 0)
					q.push(a);
				deg[a] = 1;
				if(deg[b] == 0)
					q.push(b);
				deg[b] = 1;
			}
		}
	}

	while(!q.empty()){
		int i = q.front();
		q.pop();
		for(int a=0;a<n;a++){
			if(i == a) continue;
			if(ig(i, a) || (deg[a] == 0 && strcmp(s[i][0], s[a][0]) == 0)){
				if(deg[a] == 1){
					puts("NO");
					return 0;
				}
				q.push(a);
				deg[a] = 1;
			}
		}

	}
	puts("YES");
	for(int a=0;a<n;a++){
		printf("%s\n", s[a][deg[a]]);
	}
}
