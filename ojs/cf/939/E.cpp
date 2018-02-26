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

const int MAXN = 512345;

int n, m, k;

multiset<ll> q;

ll cnt = 0, sum = 0;
ll mx = LLONG_MIN;

void add(ll x){
	if(mx != LLONG_MIN)
		q.insert(mx);
	mx = x;
	while(q.size() > 0 && (sum+mx) > (*q.begin())*(cnt+1)){
		sum += *q.begin();
		cnt++;
		q.erase(q.begin());
	}
}

void qry(){
	printf("%.20f\n", (double)mx - (((double)sum+mx)/((double)cnt+1)));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			ll x;
			scanf("%lld", &x);
			add(x);
		}
		else
			qry();
	}
}

