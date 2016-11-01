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
int s[MAXN][2];

int main (){
	scanf("%d", &n);
	int tl, tr;
	tl = tr = 0;

	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a][0], &s[a][1]);
		tl += s[a][0];
		tr += s[a][1];
	}
	if(tl < tr){
		swap(tl, tr);
		for(int a=0;a<n;a++){
			swap(s[a][0], s[a][1]);
		}
	}
	int res;
	int ir = -1;
	if(tl == tr){
		res = 0;
		for(int a=0;a<n;a++){
			if(res < s[a][0] + s[a][1]){
				res = s[a][0] + s[a][1];
				ir = a;
			}
		}
	}
	else{
		res = abs(tl - tr);
		for(int a=0;a<n;a++){
			if(res < abs((tl - s[a][0] + s[a][1]) - (tr - s[a][1] + s[a][0]))){
				res =  abs((tl - s[a][0] + s[a][1]) - (tr - s[a][1] + s[a][0]));
				ir = a;
			}
		}
	}
	printf("%d\n", ir+1);

}
