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

const int MAXN = 2123456;

int n, m, k;
int s[MAXN];
int c[MAXN];
int cnt[MAXN];
int adj[1003][1003];

int main (){
	memset(c, 0, sizeof(c));
	for(int a=2;a<1005;a++){
		if(c[a]) continue;
		for(int b=a;b*a < MAXN;b++){
			c[a*b] = 1;
		}
	}
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		cnt[s[a]]++;
	}
	int res = 1;
	int x, y, z;
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			if(c[s[a] + s[b]]) continue;
			adj[a][b] = 1;
			adj[b][a] = 1;
			res = 2;
			x = s[a];
			y = s[b];
			for(int c=0;c<b;c++){
				if(c == a) continue;
				if(adj[a][c] + adj[b][c] == 2){
					res = 3;
					z = s[c];
				}
			}

		}
	}
	if(cnt[1] + (cnt[2] != 0) > res){
		printf("%d\n", cnt[1] + (cnt[2] != 0));
		for(int a=0;a<cnt[1];a++)
			printf("1 ");
		if(cnt[2] != 0)
			printf("2\n");
		return 0;
	}
	if(res == 1)
		printf("1\n%d\n", s[0]);
	else if(res == 2)
		printf("2\n%d %d\n", x, y);
	else
		printf("3\n%d %d %d\n", x, y, z);
}
