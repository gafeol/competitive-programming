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

const int MAXN = 112345;

int n, m, k;
int s[MAXN], ok[MAXN], res;

multiset<int> q;

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		ok[a] = ((a+1)%(m+1) == 0 && a != 0);
	}
	for(int a=n-1;a>=0;a--){
		q.insert(-s[a]);
		if(ok[a]){
			q.erase(q.begin());
		}
	}

	while(!q.empty()){
		res += -(*q.begin());
		q.erase(q.begin());
	}

	printf("%d\n", res);
}

