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

int n, m, k, mrk[MAXN];

vector<int> s[MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &k);
		for(int a=0;a<n;a++)
			s[a].clear();
		for(int a=0;a<n;a++){
			int tam;
			scanf("%d", &tam);
			while(tam--){
				int val;
				scanf("%d", &val);
				s[a].pb(val);
			}
		}
		int res =0;
		for(int i=0;i<n;i++){
			for(int val: s[i])
				mrk[val] = 1;
			int sz = s[i].size();
			for(int j=i+1;j<n;j++){
				int cnt = sz;
				for(int val : s[j]){
					if(mrk[val] == 0)
						cnt++;
				}
				if(cnt == k)
					res++;
			}
			for(int val: s[i])
				mrk[val] = 0;
		}
		printf("%d\n", res);
	}
}
