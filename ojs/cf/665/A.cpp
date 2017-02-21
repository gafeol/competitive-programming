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

int h, m, fh, fm;
int b, tb;

bool men(int hi, int mi, int hh, int mm){
	return (hi < hh || (hi == hh && mi < mm));
}

bool meni(int hi, int mi, int hh, int mm){
	return (hi < hh || (hi == hh && mi <= mm));
}

bool valid(int hh, int mm){
	int hf = hh + (mm+tb)/60;
	int mf = (mm+tb)%60;
	if(meni(hf, mf, h, m)) return false;
	if(!men(hh, mm, fh, fm)) return false; 
	debug("true com %d:%d - %d:%d\n", hh, mm, hf, mf); 
	return true;
}

int main (){
	int a, ta;
	scanf("%d %d %d %d", &a, &ta, &b, &tb);
	scanf("%d:%d", &h, &m);
	fh = h + (m+ta)/60;
	fm = (m + ta)%60;
	int hh = 5, mm = 0;
	int res = 0;
	while(hh < 24){
		if(valid(hh, mm))
			res++;
		hh = hh + (mm + b)/60;
		mm = (mm+b)%60;
	}
	printf("%d\n", res);
}
