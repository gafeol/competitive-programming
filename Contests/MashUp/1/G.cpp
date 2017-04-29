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
int v1[MAXN], v2[MAXN];

int main (){
	int S;
	scanf("%d", &S); 
	for(int i = 0; i < S; i++) 
		scanf("%d", &v1[i]);
	for(int i = 0; i < S; i++)
		scanf("%d", &v2[i]);
	sort(v1,v1+S);
	sort(v2,v2+S);
	int j = 0;
	int ans = 0;
	for(int i = 0; i < S; i++) {
		for(; j < S; j++) {
			if(v2[j] > v1[i]) {
				ans++;
				j++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
