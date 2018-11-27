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

const int MAXN = 212;

int n, m, k;
int s[MAXN];

char ans[MAXN];

map<char, bool> wr[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &m, &n);
		for(int a=0;a<m;a++){
			ans[a] = 0;
			wr[a].clear();
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				char c, v;
				scanf(" %c %c", &c, &v);
				if(v == 'T')
					ans[b] = c;
				else
					wr[b][c] = true;
			}
		}
		for(int a=0;a<m;a++){
			if(wr[a].size() == 3){
				for(char c = 'A';;c++){
					if(wr[a][c] == false){
						ans[a] = c;
						break;
					}
				}
			}
		}
		for(int a=0;a<m;a++){
			if(ans[a])
				printf("%c", ans[a]); 
			else
				printf("?");
			printf("%c", " \n"[a==m-1]);
		}
	}
}

