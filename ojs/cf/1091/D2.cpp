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

int main (){
	scanf("%d", &n);
	vector<int> v, ans;
	for(int a=0;a<n;a++){
		v.pb(a+1);
	}
	do{
		for(int a=0;a<n;a++){
			ans.pb(v[a]);
		}
	}while(next_permutation(v.begin(), v.end()));
	
	for(int a=0;a<ans.size();a++){
		if(a%n == 0)
			printf("| ");
		printf("%d ", ans[a]);
	}
	puts("");
	int res = 0;
	for(int a=0;a<=ans.size()-n;a++){
		int som = 0;
		for(int i=0;i<n;i++){
			som += ans[a+i]; 
		}
		if(a%n == 0)
			printf("| ");
		printf("%d ", (som == (n*(n+1))/2));
		res += (som == (n*(n+1))/2);
	}
	puts("");
	printf("res %d\n", res);
}

