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

int n, k;
int s[MAXN];

int cus(int a, int b){
	int ans = 0;
	if(a%10 != b%10)
		ans++;
	a/=10;
	b/=10;
	if(a%10 != b%10)
		ans++;
	return ans;
}

void print(int i){
	if((i/10)%10 == 0)
		printf("0");
	printf("%d", i);
}

int main (){
	scanf("%d", &n);
	int h, m;
	scanf("%d:%d", &h, &m);
	int hr, mr;
	int res = INT_MAX;
	if(n == 12){
		for(int a=1;a<=12;a++){
			res = min(res, cus(h, a));
			if(res == cus(h, a))
				hr = a;
		}
	}
	else{
		for(int a=0;a<24;a++){
			res = min(res, cus(h, a));
			if(res == cus(h, a))
				hr = a;
		}
	}
	int ans = INT_MAX;
	for(int a=0;a<60;a++){
		ans = min(ans, cus(m, a));
		if(ans == cus(m, a))
			mr = a;
	}
	print(hr);
	printf(":");
	print(mr);

}
