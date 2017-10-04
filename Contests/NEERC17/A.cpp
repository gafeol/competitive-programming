
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
int s[200][20];
int p[200];

int main (){
	scanf("%d", &n);
	k = 0;
	for(int i=0;i<n;i++){
		scanf("%d %d", &s[i+1][0], &s[i+1][1]);
		if (s[i+1][0] == 0) p[k++] = i+1;
	}
	int j = 1;
	int cur = p[0];
	for(;;) {
		if (s[cur][1] == 0) {
			if (j == k) break;
			else {
				s[cur][1] = p[j++];
				s[s[cur][1]][0] = cur;
			}
		}
		cur = s[cur][1];
	}
	for (int i=0;i<n;i++) {
		printf("%d %d\n", s[i+1][0], s[i+1][1]);
	}
}

