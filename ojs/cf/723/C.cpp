

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
int s[MAXN], mrk[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(s[a] <= m)
			mrk[s[a]]++;
	}
	int k = n/m;
	int b = 1;
	int cnt = 0;
	for(int a=0;a<n;a++){
		if(s[a] > m || mrk[s[a]]> k){
			while(b <= m && mrk[b] >= k)
				b++;
			if(b == m+1)
				continue;
			cnt++;
			if(s[a] <= m)
				mrk[s[a]]--;
			s[a] = b;
			mrk[b]++;

		}
	}
	printf("%d %d\n", k, cnt);
	for(int a=0;a<n;a++){
		printf("%d ", s[a]);
	}

}
