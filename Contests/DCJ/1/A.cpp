#include"pancakes.h"
#include<message.h>
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

#define MASTER 0

int main (){
	ll res = 0;
	ll m = NumberOfNodes();
	ll id = MyNodeId();
	ll N = GetStackSize();
	ll l = (N/(m-1))*id, r = (N/(m-1))*(id+1);
	if(!id && r == 0)
		r = N;
	ll bef;
	if(l == 0)
		bef = LLONG_MAX;
	else
		bef = GetStackItem(l-1);
//	printf("nd %lld l %lld r %lld\n", id, l, r);
	for(ll i = l;i < min(N, r);i++){
//		printf("get i %lld\n", i);
		ll atu = GetStackItem(i);	
		// se atu == bef?
		if(atu < bef)
			res++;
		bef = atu;
	}
	PutLL(MASTER, res);
	Send(MASTER);
	if(!id){
		ll ans = 0;
		for(ll i =0;i < m;i++){
			Receive(i);
			ans = ans + GetLL(i);
		}	
		printf("%lld\n", ans);
	}
}
