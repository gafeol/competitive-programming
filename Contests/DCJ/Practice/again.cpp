#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }


#include <message.h>
#include "again.h"

#define MASTER_NODE 0
#define LARGE_PRIME 1000000007
typedef long long ll;

inline ll mod(ll x){
	return ((x%LARGE_PRIME) + LARGE_PRIME)%LARGE_PRIME;
}

long long sa[30], sb[30];
int main() {
	ll soma = 0, somb = 0;
	ll no = NumberOfNodes();
	ll id = MyNodeId();
	ll N = GetN();

	for (long long i = id; i < N; i+=no) {
		soma = soma + GetA(i);
		somb = somb + GetB(i);
	}
	soma = mod(soma);
	somb = mod(somb);
	PutLL(MASTER_NODE, soma);
	PutLL(MASTER_NODE, somb);
	Send(MASTER_NODE);

	if (id == MASTER_NODE) {
		soma = 0;
		somb = 0;
		for (ll node = 0; node < no; ++node) {
			Receive(node);
			ll vala = GetLL(node);
			ll valb = GetLL(node);
			soma = soma + vala;
			somb = somb + valb;
			sa[node] = vala;
			sb[node] = valb;
		}
		soma = mod(soma);
		somb = mod(somb);
		long long res = mod(soma*somb);
		for(ll pc = 0;pc < no;pc++){
			ll j = (no - pc)%no;
			res = mod(res - mod(sa[pc]*sb[j]));
		}
		printf("%lld\n", res);
	} 
}
