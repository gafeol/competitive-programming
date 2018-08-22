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
int s[MAXN];

bool cmp(int a, int b){
	return a > b;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	sort(s, s+n, cmp);
	int j = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		while(j+1 < n && s[i] > s[j+1] && s[j+1] + k >= s[i])
			j++;
		if(i == j){
			ans++; 
			j++;
		}
	}
	printf("%d\n", ans);
}

