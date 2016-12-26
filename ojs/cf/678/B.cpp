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

int biss(int a){
	return (a%400 == 0 || (a%4 == 0 && a%100 != 0));
}

int main (){
	scanf("%d", &n);
	int a, cnt = 0;
	if(biss(n)){
		for(a=n+1;;a++){
			if(a%400 == 0 || (a%4 == 0 && a%100 != 0))
				cnt+=2;
			else
				cnt++;
			if(cnt != 0 && cnt%7==0 && biss(a))
				break;
		}
	}
	else{
		for(a=n+1;;a++){
			if(biss(a))
				cnt+=2;
			else
				cnt++;
			if(cnt%7 == 0 && cnt != 0 && !biss(a))
				break;
		}
	}
	printf("%d\n", a);
}
