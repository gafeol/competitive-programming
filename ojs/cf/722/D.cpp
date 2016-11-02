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

multiset<int> q;

map<int, int> ind;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		q.insert(-s[a]);
		ind[s[a]] = 1;
	}
	while(1){
		int t = -(*q.begin());
		int v = t;
		while((v/2) > 0){
			v/=2;
			if(ind.find(v) == ind.end())
				break;
		}
		if(ind.find(v) != ind.end())
			break;
		ind.erase(t);
		ind[v] = 1;
		q.erase(-t);
		q.insert(-v);
	}
	while(!q.empty()){
		int t = *q.begin();
		printf("%d ", -t);
		q.erase(t);
	}


}
