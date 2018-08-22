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
multiset<int> q;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x;
		scanf("%d", &x);
		q.insert(x);
	}

	int t = 0;
	while(q.size() > 1){
		if((t&1))
			q.erase(q.begin());
		else
			q.erase(q.find(*q.rbegin()));
		t++;
	}
	printf("%d\n", *q.begin());
}

