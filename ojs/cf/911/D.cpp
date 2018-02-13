
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

const int MAXN = 2123;

int n, m, k;
int s[MAXN];

int bit[MAXN];

void upd(int i){
	i += 2;
	while(i > 0){
		bit[i]++;
		i -= (i&-i);
	}
}

int qry(int i){
	i+=2;
	int ans = 0;
	while(i < MAXN){
		ans += bit[i];
		i += (i&-i);
	}
	return ans;
}
int inv = 0;

void print(){
	if(inv)
		puts("odd");
	else
		puts("even");
}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
		inv += qry(s[a]);
		upd(s[a]);
	}
	inv = (inv&1);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);	
		if(i == j)
			print();
		else{
			if((((j-i+1)*(j-i))/2)&1){
				inv = 1 - inv;
				print();
			}
			else{
				print();
			}
		}
	}
}

