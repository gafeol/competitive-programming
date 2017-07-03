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

const int MAXN = 2123;

int n, m, k;
char v[MAXN], s[MAXN];

int main (){
	scanf("%d", &n);
	scanf("%d", &m);
	scanf(" %s %s", s, v);
	int res = INT_MAX;
	for(int i=0;i<m-n+1;i++){
		int ans = 0;
		for(int j=0;j<n;j++){
			if(s[j] != v[i+j])
				ans++;
		}
		res = min(ans, res);
	}
	printf("%d\n", res);
	for(int i=0;i<m-n+1;i++){
		int ans = 0;
		for(int j=0;j<n;j++){
			if(s[j] != v[i+j])
				ans++;
		}
		if(res == ans){
			for(int j=0;j<n;j++){
				if(s[j] != v[i+j])
					printf("%d ", j+1);
			}
			return 0;
		}
	}
}
