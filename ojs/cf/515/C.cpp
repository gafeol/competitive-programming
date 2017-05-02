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

int v[10];

void add(int val){
	if(val <= 1) return ;
	if(val == 2){
		v[2]++;
	}
	else if(val == 3)
		v[3]++;
	else if(val == 4){
		v[2]+=2;
		v[3]++;
	}
	else if(val == 5)
		v[5]++;
	else if(val == 6){
		v[3]++;
		v[5]++;
	}
	else if(val == 7)
		v[7]++;
	else if(val == 8){
		v[2] += 3;
		v[7]++;
	}
	else if(val == 9){
		v[3] += 2;
		v[2]++;
		v[7]++;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = c - '0';
		add(s[a]);
	}
	for(int a=9;a>=0;a--){
		while(v[a]){
			printf("%d", a);
			v[a]--;
		}
	}
	printf("\n");
}
