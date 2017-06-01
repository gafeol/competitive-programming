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
pii s[3][2];

bool inter(int a, int b, int aa, int bb){
	if(a > b)
		swap(a, b);
	if(aa > bb)
		swap(aa, bb);
	if(a > bb || b < aa)
		return false;
	return true;
}

int main (){
	for_tests(t, tt){
		int d[3];
		//0 hor
		//1 ver
		for(int a=0;a<2;a++){
			for(int b=0;b<2;b++){
				scanf("%d %d", &s[a][b].fst, &s[a][b].snd);
				
			}
			d[a] = (s[a][0].fst == s[a][1].fst);
		}
		if(s[0][0] == s[0][1])
			d[0] = d[1];
		if(s[1][0] == s[1][1])
			d[1] = d[0];
		if(d[0] == d[1]){
			if(d[0] == 0){
				swap(s[0][0].fst, s[0][0].snd);
				swap(s[0][1].fst, s[0][1].snd);
				swap(s[1][0].fst, s[1][0].snd);
				swap(s[1][1].fst, s[1][1].snd);
			}
			if(s[0][0].fst == s[1][0].fst){
				if(inter(s[0][0].snd, s[0][1].snd, s[1][0].snd, s[1][1].snd))
					puts("yes");
				else
					puts("no");
			}
			else
				puts("no");
		}
		else{
			if(s[0][0] == s[1][0] || s[0][0] == s[1][1] || s[0][1] == s[1][0] || s[0][1] == s[1][1])
				puts("yes");
			else
				puts("no");
		}
	}
}
