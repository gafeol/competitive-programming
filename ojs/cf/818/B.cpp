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
int nxt[MAXN];
int mrk[MAXN];
int s[MAXN];

int d(int i, int j){
	int ans = j - i;
	if(ans <= 0) 
		ans += n;
	return ans;
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d", nxt+a);	
	}
	for(int a=0;a<m-1;a++){
		if(s[nxt[a]] != 0){
			if(d(nxt[a], nxt[a+1]) != s[nxt[a]]){
				puts("-1");
				return 0;
			}
			else continue;
		}
		if(!mrk[d(nxt[a], nxt[a+1])]){
			s[nxt[a]] = d(nxt[a], nxt[a+1]);
			mrk[d(nxt[a], nxt[a+1])] = 1;
		}
		else{
			puts("-1");
			return 0;
		}
	}
	for(int a=1;a<=n;a++){
		if(s[a] == 0){
			int b = 1;
			while(mrk[b])
				b++;
			s[a] = b;
			mrk[b] = 1;
		}
		printf("%d ", s[a]);
	}
}
