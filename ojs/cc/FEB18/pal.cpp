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
char s[MAXN];
int cnt[MAXN], res[MAXN];

queue<int> pos[MAXN];

int main (){
	for_tests(t, tt){
		scanf(" %s", s);
		n = strlen(s);
		for(int a=0;a<n;a++){
			cnt[s[a]]++;
			pos[s[a]].push(a);
		}
		m = n+1;
		s[m] = -1;
		int ok = 1;
		for(int a=0;a<n;a++){
			if(s[m] != s[a] && (cnt[s[a]]&1)){
				if(m != n+1)
					ok = 0;
				m = a;
			}
		}
		if(ok){
			int i = 0;
			for(int a=0;a<n/2;a++){
				if(pos[s[i]].size() > 1){
					res[a] = pos[s[i]].front();
					pos[s[i]].pop();
					res[n - a - 1] = pos[s[i]].front();
					pos[s[i]].pop();
				}
				else{
					i++;
					a--;
				}
			}
			if((n&1))
				res[n/2] = pos[s[m]].front();
		}
		for(int a=0;a<n;a++){
			cnt[s[a]] = 0;
			while(!pos[s[a]].empty())
				pos[s[a]].pop();
		}
		if(!ok){
			puts("-1");
			continue;
		}
		else{
			for(int a=0;a<n;a++)
				printf("%d ", res[a]+1);
			puts("");

		}
	}
}

