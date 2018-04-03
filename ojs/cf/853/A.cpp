#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
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

#define time asdadas

const int MAXN = 612345;

int n, m, k;
ll s[MAXN];
ll sum = 0;

int ans[MAXN];

multiset<pii> q;

void add(int i){
	pii aux = pii(-s[i], i);
	sum += s[i];
	q.insert(aux);
}

int time = 0;
void rmv(){
	pii x = *q.begin();
	q.erase(q.begin());
	sum += x.fst;
	ans[x.snd] = time+1;
}


int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld", s+a); 
	}

	ll res = 0;
	for(int a=0;a<k;a++){
		add(a);
		res += sum;
		time++;
	}
	for(int a=k;a<n+k;a++){
		add(a);
		rmv();
		res += sum;
		time++;
	}
	printf("%lld\n", res);
	for(int a=0;a<n;a++){
		printf("%d ", ans[a]);
	}
	puts("");
}
