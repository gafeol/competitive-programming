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

int s[MAXN];
int cnt[MAXN];


void w(){
	puts("YES");
	exit(0);
}

void f(){
	puts("NO");
	exit(0);
}

void go(int bm){
	int pos[3];
	int mx = 0;
	for(int a=0;a<3;a++){
		pos[a] = bm%10;
		bm/=10;
		mx = max(mx, pos[a]);
	}
	for(int a=0;a<10000;a++){
		int ok = 0;	
		for(int t=0;t<3;t++){
			if(pos[t] == a){
				pos[t] += s[t];
				ok = 1;
			}
		}
		if(!ok && a > mx)
			return ;
	}
	w();
}

int main (){
	for(int a=0;a<3;a++){
		scanf("%d", s+a);
		cnt[s[a]]++;
	}
	sort(s, s+3);
	/*if(s[0] == 1)
		w();
	if(cnt[2] == 2)
		w();
	if(cnt[3] == 3)
		w();
*/
	if(s[0] > 9)
		f();
	for(int a=0;a<1000;a++){
		go(a);
	}
	f();
}

